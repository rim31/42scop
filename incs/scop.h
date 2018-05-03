/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:44:13 by oseng             #+#    #+#             */
/*   Updated: 2017/12/11 14:17:30 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libft.h"


// # include "mlx_macros.h"
// # include <mlx.h>
// # include <mlx_opengl.h>
// # include <stdio.h>
// # include <math.h>
// # include <stdbool.h>
// # include <time.h>
// # include <fcntl.h>
// # include <openGL/gl3.h>
//
// # define WIN_WIDTH		720
// # define WIN_HEIGHT		720
//
// # define TRUE			1
// # define FALSE			0
//
// # define VERTEX_SHADER	"./shaders/vertex_shader.shader"
// # define FRAGMENT_SHADER	"./shaders/fragment_shader.shader"
//
// typedef struct s_env	t_env;
// typedef struct s_vector t_vector;
// typedef struct s_object	t_object;
// typedef int				(*t_tab)(int, int, int, t_env *);
//
// struct			s_vector
// {
// 	float		x;
// 	float		y;
// 	float		z;
// };
//
// struct			s_object
// {
// 	int			face_count;
// 	int			vertices_count;
// 	char		*name;
// 	float		**vertices;
// 	float		*colors;
// 	float		*points;
// 	float 		*uv_map;
// 	int			**faces;
// 	int			shading;
// 	double		rotation_y;
// 	char		*texture;
// 	int 		transition_state;
// 	float		transition_value;
// 	GLfloat		*projection_matrix;
// 	GLfloat		*translation_matrix;
// 	GLfloat		*scale_matrix;
// 	GLfloat		*rotation_matrix;
// 	GLfloat		*view_matrix;
// 	GLuint		vbo;
// 	GLuint		vbo_colors;
// 	GLuint		vbo_uvs;
// 	t_vector	position;
// };
//
// struct			s_env
// {
// 	void		*mlx;
// 	void		*win;
// 	void		*img;
// 	t_object	object;
// 	GLuint		shader_programme;
// };
//
// void			display(t_object object, GLint shader_programme);
// void			init_object(t_object *obj, char *filename);
// int				object_loader(char *file_name, t_object *object);
// GLfloat		*uv_map(int size);
//
// /*
// ** Matrices
// */
//
// GLfloat 	*create_matrix(int size);
// void			rotation_y_matrix(GLfloat *matrix, float angle);
// void			projection_matrix(GLfloat *matrix, float fov, float aspect);
// void			translation_matrix(GLfloat *matrix, float x, float y, float z);
// void			scale_matrix(GLfloat *matrix, float x, float y, float z);
//
// /*
// ** Data binding
// */
//
// GLint			create_vbo(int size, int data_size, float *data);
// void			bind_vbo(int index, GLuint id, int size);
// void			pass_uniforms(t_object *obj, GLuint shader_programme);
// void			upload_texture(char *texture_data);
//
// GLuint		create_shader_program();
// void			load_texture(t_env *e);
// float			*generate_colors(int obj_size);
// int				key_p(int keycode, t_env *e);

#endif
