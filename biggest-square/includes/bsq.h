/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwijeon <hwijeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:36:22 by hwijeon           #+#    #+#             */
/*   Updated: 2023/03/02 11:53:33 by hwijeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "pos.h"
# include "buffer.h"

# define STDIN_SAVE "standard_input_map"

char		*strdup_term(char *src, char *charset);
char		*strlen_term(char *src, char *charset);
int			cf_strlen(char *src);
char		*strcpy_term(char *dest, char *src, char *charset);
long long	cf_atol(char *str);
int			min_tri(int a, int b, int c);
void		get_map_info(char *file_name, char **marks, long long *row_size);
void		map_error(void);
int			get_line_size(char *file_name);
int			*create_dp(char *file_name, t_pos *max_pos);
int			is_newline(int x_init, char target, t_pos *dp_idx);
int			is_in_square(t_pos cur, t_pos max_pos);
int			skip_first_line(char *buffer);
void		save_max_pos(t_pos *max_pos, int cur_value, t_pos cur);
int			read_first_line(int fd, char *buffer, int *idx, t_pos *dp_idx);
long long	set_max_pos_dp(int fd, int *dp, char *marks, t_pos *max);
t_pos		find_max_pos(char *file_name, char *marks, long long row_num);
void		read_next_if_buffer_end(int fd, int *idx, char *buffer, int *bytes);
void		print_if_buffer_end(int fd, int *idx, char *buffer, int *bytes);
void		print_max_square(char *file_name, t_pos max_pos, char sqare);
void		not_existing_map(void);
void		dp_init_pos(t_pos *pos);
void		max_init_pos(t_pos *pos);
void		error_init_pos(t_pos *pos);
int			is_error_pos(t_pos pos);

#endif