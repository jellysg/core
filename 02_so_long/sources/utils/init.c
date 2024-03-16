#include "../../includes/so_long.h"

void	init_map(t_data *init)
{
	init->map->e_count = 0;
	init->map->p_count = 0;
	init->map->c_count = 0;
	init->map->m_count = 0;
	init->map->e_found = 0;
	init->map->c_found = 0;
	init->map->current_line = 0;
	init->map->current_col = 0;
	init->map->len = 0;
	init->map->fd = 0;
	init->map->row = 0;
	init->map->col = 0;
	init->map->start_row = -1;
	init->map->start_col = -1;
}

void	init_vars(t_data *init)
{
	init_map(init);
	init->player->x = 0;
	init->player->y = 0;
	init->player->moves = 0;
	init->player->score = 0;
	init->player->win = 0;
	init->player->facing = 'L';
	init->monster->num = 0;
	init->monster->idle_time = 10;
	init->monster->facing = 'R';
}

void	init_struct_pointers(t_data *data)
{
    t_map   *c;
    t_player    *p;
	t_monster	*m;
    t_texture   *t;

    c = malloc(sizeof(t_map));
    p = malloc(sizeof(t_player));
	m = malloc(sizeof(t_monster));
    t = malloc(sizeof(t_texture));

	data->map = c;
    data->player = p;
	data->monster = m;
    data->texture = t;
	return;
}

int	init_player_pos(t_map *c, t_player *p, int row, int col)
{
    while (row < c->current_line)
    {
		col = 0;
        while (col < c->len)
        {
            if (c->map[row][col] == 'P')
            {
                p->y = row;
                p->x = col;
                c->start_row = row;
                c->start_col = col;
                return (1);
            }
			col++;
        }
        if (c->start_row != -1)
            break;
		row++;
    }
    if (c->start_row == -1)
	{
        return (0);
	}
	return (1);
}