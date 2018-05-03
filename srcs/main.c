/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:11:00 by oseng             #+#    #+#             */
/*   Updated: 2017/12/11 13:21:06 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int					loop_hook(t_env *e)
{
	e->object.rotation_y += 1;
	if (e->object.rotation_y >= 360.0f)
		e->object.rotation_y = 0;
	if (e->object.transition_state != 0
		&& e->object.transition_value != 0
		&& e->object.transition_value != 1)
	{
		if (e->object.transition_state == -1)
			e->object.transition_value -= 0.05;
		else
			e->object.transition_value += 0.05;
		if (e->object.transition_value <= 0.0f
			|| e->object.transition_value >= 1.0f)
			e->object.transition_state = 0;
	}
	rotation_y_matrix(e->object.rotation_matrix, e->object.rotation_y);
	display(e->object, e->shader_programme);
	mlx_opengl_swap_buffers(e->win);
	return (0);
}

GLfloat				*uv_map(int size)
{
	GLfloat	*uv_map;
	int		i;

	i = 0;
	if (!(uv_map = (GLfloat*)malloc(size * 2 * sizeof(GLfloat))))
		return (NULL);
	while (i < size * 2 && i + 6 < size * 2)
	{
		uv_map[i++] = 0.0f;
		uv_map[i++] = 1.0f;
		uv_map[i++] = 1.0f;
		uv_map[i++] = 0.0f;
		uv_map[i++] = 1.0f;
		uv_map[i++] = 1.0f;
	}
	return (uv_map);
}

void				center_points(float *points, int size)
{
	float		result[3];
	int			i;

	i = 0;
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	while (i < size * 3)
	{
		result[0] += points[i];
		result[1] += points[i + 1];
		result[2] += points[i + 2];
		i += 3;
	}
	result[0] /= size;
	result[1] /= size;
	result[2] /= size;
	i = 0;
	while (i < size * 3)
	{
		points[i] -= result[0];
		points[i + 1] -= result[1];
		points[i + 2] -= result[2];
		i += 3;
	}
}

int					main(int ac, char **av)
{
	t_env			e;

	printf("test: %i\n", ft_atoi("7/3/7"));
	if (ac > 1)
		init_object(&e.object, av[1]);
	if (!(e.mlx = mlx_init()))
	{
		ft_putendl("Env error");
		return (-1);
	}
	e.win = mlx_new_opengl_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "scop");
	mlx_opengl_window_set_context(e.win);
	printf("Renderer: %s\nOpenGL version supported: %s\n",
		glGetString(GL_RENDERER), glGetString(GL_VERSION));
	load_texture(&e);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	center_points(e.object.points, e.object.face_count * 3);
	e.shader_programme = create_shader_program();
	display(e.object, e.shader_programme);
	mlx_opengl_swap_buffers(e.win);
	mlx_hook(e.win, 2, (1L << 0), key_p, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
