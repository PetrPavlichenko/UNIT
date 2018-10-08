
#ifndef SH_H

# define SH_H

# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

# define RESET "\033[m"
# define RESETR "\033[000000m"
# define RED "\033[31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[36"

char	**splitspaces(char const *s);
void	check_command(char **inp, char ***env);
void	chd_error(char *path);
void	ft_error_dir(char *str);
char	*ft_getpwd(void);
char	**alloc_env(char **env);
void	free_arr(char **arr);
char	**ft_add_line(char **arr, char *line);
char	**ft_unset(char **arr, int i);
void	ft_setenv(char **inp, char ***env);
void	norm_setenv(char **inp, char ***env, int i, int k);
void	ft_cd(char **inp, char ***env);
void	norm_cd(char **inp, char **env, char *path, char *t);
void	norm_cd2(char **inp, char **env, char *path, char *t);
void	norm_cd3(char **inp, char **env, char *path, char *t);
void	ft_execve(char **inp, char **env);
void	not_found(char *str);
void	not_home(void);
void	g_r(void);
void	r_g(void);
void	ft_opwd(char ***env, char *pwd);
void	ft_putstr_echo(char const *s);
char	*ft_getpwd_m(void);
void	home_not_set(void);

#endif
