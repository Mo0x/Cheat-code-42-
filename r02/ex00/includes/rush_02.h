/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:29:39 by mgovinda          #+#    #+#             */
/*   Updated: 2023/06/25 23:35:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_dict
{
	char				*entry;
	unsigned long long	nb;
	char				*w_number;
}	t_dict;

t_dict				*dictionary_parser(char *path_dic);
t_dict				*dic_filler(int size, char *parsed_dic, t_dict *ret);
int					ft_is_charset(char c, char *charset);
int					count_entry(char *parsed_dic);
int					ft_file_size(int fd);
char				*ft_strdup_till_nl(char *src);
int					ft_strlen_till_nl(char *str);
int					args_sorter(int ac, char **av);
int					ft_check_number(char *nbr);
char				*dict_search(unsigned long long nbr, t_dict *dict);
int					ft_strlen(char *str);
unsigned long long	ft_atoull(char *str);
unsigned long long	ft_verif_ret(unsigned long long nb);
int					ft_is_numeric(char c);
int					ft_isspace(char c);
char				*ft_create_string(unsigned long long nb, t_dict *dict);
char				*ft_triplets(char *dec_string, t_dict *dict);
char				*ft_decimals(char *dec_string, t_dict *dict);
void				ft_decimals_0(t_dict *dict,
						unsigned long long *decimals, char **ret);
char				*ft_hundred(char *dec_string, t_dict *dict);
char				*ft_hundred_0(char *dec_string, char **tmp);
void				ft_hundred_1(char *dec_string,
						t_dict *dict, char **ret, char **tmp);
char				*ft_first_triplets(char *dec_string, int max, t_dict *dict);
unsigned long long	ft_power(unsigned long long nb, unsigned long long power);
char				*str_cat_malloc(char *dest, char *src);
void				ft_rev_char_tab(char *tab);
char				*ulltoa(unsigned long long nbr);
void				ft_check_flag(unsigned long long *nbr,
						char **dic_path, int flag, char **av);
char				**ft_split(char *str, char *charset, int *size);
char				*ft_strjoin(int size, char **strs, char *sep);
char				*ft_str_cleaner(char *str);
void				ft_create_string0(char **ret, int *length,
						char **dec_string, t_dict *dict);
int					ft_check_dict(char *str);
unsigned long long	dict_max(t_dict *dict);
void				ft_free_dict(t_dict *dict);
char				*str_cat_malloc_fs(char *dest, char *src);
char				*str_cat_malloc_fd(char *dest, char *src);
char				*str_cat_malloc_fds(char *dest, char *src);
void				ft_first_triplets_0(char **ret,
						unsigned long long nbr, t_dict *dict);

#endif 
