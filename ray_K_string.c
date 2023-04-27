#include "cub3d.h"

void    set_pixel(t_img *frame, int x, int y, unsigned int color)
{
    char    *pixel;

    pixel = frame->addr + (y * frame->line_len + x * (frame->bpp / 8));
    if (frame->bpp == 32)
        *(int *)pixel = color;
    else if (frame->bpp == 24)
    {
        *(pixel + 2) = (color >> 16) & 0xFF;
        *(pixel + 1) = (color >> 8) & 0xFF;
        *(pixel) = color & 0xFF;
    }
}

unsigned int get_pixel(t_img *tex, int x, int y)
{
    char *rtn;

    rtn = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
    return (*(unsigned int *)rtn);
}

void    calc_step(t_rayKsting *data, t_player *player)
{
    if(data->ray_dir_x < 0)
    {
        data->step_x = -1;
        data->side_dist_x = (player->pos_x - data->map_x) * data->delta_dist_x;
    }
    else
    {
        data->step_x = 1;
        data->side_dist_x = (data->map_x + 1.0 - player->pos_x) * data->delta_dist_x;
    }
    if (data->ray_dir_y < 0)
    {
        data->step_y = -1;
        data->side_dist_y = (player->pos_y - data->map_y) * data->delta_dist_y;
    }
    else
    {
        data->step_y = 1;
        data->side_dist_y = (data->map_y + 1.0 - player->pos_y) * data->delta_dist_y;
    }
}

void rayKsting_init(t_player *player, t_rayKsting *data, int x)
{
    double camera_x;
    
    camera_x = 2 * x / (double)WIDTH - 1;
    data->ray_dir_x = player->dir_x + player->plane_x * camera_x;
    data->ray_dir_y = player->dir_y + player->plane_y * camera_x;
    data->map_x = (int)player->pos_x;
    data->map_y = (int)player->pos_y;
    if (data->ray_dir_x == 0)
        data->delta_dist_x = 1e30;
    else
        data->delta_dist_x = fabs(1 / data->ray_dir_x);
    if (data->ray_dir_y == 0)
        data->delta_dist_y = 1e30;
    else
        data->delta_dist_y = fabs(1 / data->ray_dir_y);
    calc_step(data, player);
}

void    dda(t_rayKsting *data, char **map)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (data->side_dist_x < data->side_dist_y)
        {
            data->side_dist_x += data->delta_dist_x;
            data->map_x += data->step_x;
            data->side = 0;
        }
        else
        {
            data->side_dist_y += data->delta_dist_y;
            data->map_y += data->step_y;
            data->side = 1;
        }
        if (map[data->map_x][data->map_y] == '1')
            hit = 1;
    }
    if (data->side == 0)
        data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
    else
        data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
    data->line_height = (HEIGHT / data->perp_wall_dist);
}

void    calc_draw_params(t_rayKsting *data, t_player *player)
{
   data->pitch = 100;
   data->draw_start = -data->line_height / 2 + HEIGHT / 2 + data->pitch;
    if (data->draw_start < 0)
        data->draw_start = 0;
    data->draw_end = data->line_height / 2 + HEIGHT / 2 + data->pitch;
    if (data->draw_end >= HEIGHT)
        data->draw_end = HEIGHT - 1;
    data->tex_num = 0;
    if (data->side == 1)
        data->tex_num = 1;       
    if (data->side == 0)
        data->wall_x = player->pos_y + data->perp_wall_dist * data->ray_dir_y;
    else
        data->wall_x = player->pos_x + data->perp_wall_dist * data->ray_dir_x;
    data->wall_x -= floor(data->wall_x);
    data->tex_x = (int)(data->wall_x * TEX_WIDTH);
    if (data->side == 0 && data->ray_dir_x > 0)
        data->tex_x = 64 - data->tex_x - 1; 
    if (data->side == 1 && data->ray_dir_x < 0)
        data->tex_x = 64 - data->tex_x - 1;  
}

void    draw_roof(t_map *map, int draw_start, int *y, int x)
{
    unsigned int    color = 0x000000;
    
    while (*y < draw_start)
    {
        set_pixel(map->frame, x, *y, color);
        *y += 1;
    }
}

void    draw_floor(t_map *map, int *y, int x)
{
    unsigned int    color = 0x882222;
    
    while (*y < HEIGHT)
    {
        set_pixel(map->frame, x, *y, color);
        *y += 1;
    }
}

void    draw(t_rayKsting *data, t_map *map, t_player *player, int x)
{
    int             y;
    int             d;
    double          step;
    double          tex_pos;
    unsigned int    color;

    y = 0;
    calc_draw_params(data, player);
    step = 1.0 * TEX_HEIGHT / data->line_height;
    tex_pos = (data->draw_start - data->pitch - HEIGHT / 2 + data->line_height / 2) * step;
    draw_roof(map, data->draw_start, &y, x);
    while (y <= data->draw_end)
    {
        //data->tex_y = (((y * 2 - HEIGHT + data->line_height) << 6) / data->line_height) / 2;
        //d = (y - HEIGHT / 2 + data->line_height / 2) * 256;
        //data->tex_y = ((d * 64) / data->line_height) / 256;
        //while (data->tex_y >= 64)
        //    data->tex_y -= 64;
        data->tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
        tex_pos += step;
        color = get_pixel(map->tex[data->tex_num], data->tex_x, data->tex_y);
        if (data->side == 1)
            color = (color >> 1) & 0x7F7F7F;
        set_pixel(map->frame, x, y, color);
        y++;
    } 
    draw_floor(map, &y, x);
}

void    clear_frame(t_img *frame)
{
    int x;
    int y;
    char    *pix;

    x = -1;
    y = -1;
    while (++x < WIDTH)
    {
        while (++y < HEIGHT)
        {
            pix = frame->addr + (y * frame->line_len + x * (frame->bpp / 8));
            if (frame->bpp == 32)
                *(int *)pix = 0;
            else if (frame->bpp == 24)
            {
                *(pix) = 0;
                *(pix + 1) = 0;
                *(pix + 2) = 0;
            }
            y++;
        }
        y = 0;
        x++;
    }
}

void    ray_k_string(t_map *map, t_player *player)
{
    int x;
    int y;
    t_rayKsting ray_data;
  
    x = 0;
    while (x < WIDTH)
    {
        rayKsting_init(player , &ray_data, x);
        dda(&ray_data, map->map_cpy);
        draw(&ray_data, map, player, x);
        x++;
    }
    mlx_put_image_to_window(map->mlx->display, map->mlx->win, map->frame->img, 0, 0);
    //clear_frame(map->frame);
}