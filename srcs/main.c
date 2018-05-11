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

static t_env	ft_init(t_env *a)
{
	a->x = 0;
	a->y = 0;
	a->pas = 30;
	a->xx = 0;
	a->yy = 0;
	a->k0 = 1000000;
	a->k = 10000000;
	a->keyup = 0;
	a->keydown = 0;
	a->keyleft = 0;
	a->keyrigth = 0;
	a->nblum = 1;
	// ft_init_scene(a, i);
	return (*a);
}

int			my_key_funct(int keypress, t_env *a)
{
	if (keypress == 53)
		exit(0);
	if (keypress == 125)
		a->keyup = 1;
	else if (keypress == 126)
		a->keydown = 1;
	if (keypress == 123)
		a->keyleft = 1;
	else if (keypress == 124)
		a->keyrigth = 1;
	// if (keypress == 1 || keypress == 49 || keypress == 0)
	// 	ft_rotation(keypress, a);
	// ft_bzero((void *)a->data, (H * L * 4) - 1);
	return (0);
}

int			my_keyrelease_funct(int keyrelease, t_env *a)
{
	if (keyrelease == 125)
		a->keyup = 0;
	else if (keyrelease == 126)
		a->keydown = 0;
	if (keyrelease == 123)
		a->keyleft = 0;
	else if (keyrelease == 124)
		a->keyrigth = 0;
	return (0);
}

void display(void)
{
	float points[] = {
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
	"#version 400\n"
	"in vec3 vp;"
	"void main() {"
	"  gl_Position = vec4(vp, 1.0);"
	"}";

	const char* fragment_shader =
	"#version 400\n"
	"out vec4 frag_colour;"
	"void main() {"
	"  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
	"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	// wipe the drawing surface clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(shader_programme);
	glBindVertexArray(vao);
	// draw points 0-3 from the currently bound VAO with current in-use shader
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void	ft_start_screen(t_env a)
{


	ft_putstr("lol\n");
	if (a.x > L || a.x < 0 || a.y > H || a.y < 0 || H < 1 || L < 1)
		exit(0);
	a.mlx = mlx_init();
	// a.win = mlx_new_window(a.mlx, L, H, "mlx 42");
	// a.win = mlx_new_opengl_window(a.mlx, L, H, "mlx scop42");
	a.win = mlx_new_opengl_window(a.mlx, L, H, "scop");
	mlx_opengl_window_set_context(a.win);
	ft_putendl((char *)glGetString(GL_RENDERER));
	ft_putendl((char *)glGetString(GL_VERSION));
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	display();

	mlx_opengl_swap_buffers(a.win);
	mlx_hook(a.win, 2, (1L << 0), my_key_funct, &a);
	// mlx_hook(a.win, 3, (1L << 1), my_keyrelease_funct, &a);
	mlx_loop(a.mlx);
}

int				main(int argc, char **argv)
{
	int fd;
	t_env		*a;
	char *buff;

	fd = 0;
	ft_putstr("\033[92mEnter a .obj\n\033[0m");
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			exit(0);
		a = malloc(sizeof(t_env));
		while ((get_next_line(fd, &buff)) > 0)
		{
			ft_putendl(buff);
			free(buff);
		}
		close(fd);
		*a = ft_init(a);
		ft_start_screen(*a);
	}
		else
			ft_putstr("\033[96mERROR :-P\n\033[0m");
	return (0);
}

































//
// int					loop_hook(t_env *e)
// {
// 	e->object.rotation_y += 1;
// 	if (e->object.rotation_y >= 360.0f)
// 		e->object.rotation_y = 0;
// 	if (e->object.transition_state != 0
// 		&& e->object.transition_value != 0
// 		&& e->object.transition_value != 1)
// 	{
// 		if (e->object.transition_state == -1)
// 			e->object.transition_value -= 0.05;
// 		else
// 			e->object.transition_value += 0.05;
// 		if (e->object.transition_value <= 0.0f
// 			|| e->object.transition_value >= 1.0f)
// 			e->object.transition_state = 0;
// 	}
// 	rotation_y_matrix(e->object.rotation_matrix, e->object.rotation_y);
// 	display(e->object, e->shader_programme);
// 	mlx_opengl_swap_buffers(e->win);
// 	return (0);
// }
//
// GLfloat				*uv_map(int size)
// {
// 	GLfloat	*uv_map;
// 	int		i;
//
// 	i = 0;
// 	if (!(uv_map = (GLfloat*)malloc(size * 2 * sizeof(GLfloat))))
// 		return (NULL);
// 	while (i < size * 2 && i + 6 < size * 2)
// 	{
// 		uv_map[i++] = 0.0f;
// 		uv_map[i++] = 1.0f;
// 		uv_map[i++] = 1.0f;
// 		uv_map[i++] = 0.0f;
// 		uv_map[i++] = 1.0f;
// 		uv_map[i++] = 1.0f;
// 	}
// 	return (uv_map);
// }
//
// void				center_points(float *points, int size)
// {
// 	float		result[3];
// 	int			i;
//
// 	i = 0;
// 	result[0] = 0;
// 	result[1] = 0;
// 	result[2] = 0;
// 	while (i < size * 3)
// 	{
// 		result[0] += points[i];
// 		result[1] += points[i + 1];
// 		result[2] += points[i + 2];
// 		i += 3;
// 	}
// 	result[0] /= size;
// 	result[1] /= size;
// 	result[2] /= size;
// 	i = 0;
// 	while (i < size * 3)
// 	{
// 		points[i] -= result[0];
// 		points[i + 1] -= result[1];
// 		points[i + 2] -= result[2];
// 		i += 3;
// 	}
// }
//
// int					main(int ac, char **av)
// {
// 	t_env			e;
//
// 	printf("test: %i\n", ft_atoi("7/3/7"));
// 	if (ac > 1)
// 		init_object(&e.object, av[1]);
// 	if (!(e.mlx = mlx_init()))
// 	{
// 		ft_putendl("Env error");
// 		return (-1);
// 	}
// 	e.win = mlx_new_opengl_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "scop");
// 	mlx_opengl_window_set_context(e.win);
// 	printf("Renderer: %s\nOpenGL version supported: %s\n",
// 		glGetString(GL_RENDERER), glGetString(GL_VERSION));
// 	load_texture(&e);
// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LESS);
// 	center_points(e.object.points, e.object.face_count * 3);
// 	e.shader_programme = create_shader_program();
// 	display(e.object, e.shader_programme);
// 	mlx_opengl_swap_buffers(e.win);
// 	mlx_hook(e.win, 2, (1L << 0), key_p, &e);
// 	mlx_loop_hook(e.mlx, loop_hook, &e);
// 	mlx_loop(e.mlx);
// 	return (0);
// }
