/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:29:57 by flegg             #+#    #+#             */
/*   Updated: 2021/01/19 15:39:14 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	data_worker(t_gnl_data *data, int *endl_pos, char **line)
{
	char				*tmpstr;

	*endl_pos = ft_strchrpos(data->prestr, '\n');
	tmpstr = (char *)malloc(*endl_pos + 1);
	if (!tmpstr)
		return (-1);
	ft_memmove(tmpstr, data->prestr, *endl_pos);
	*(tmpstr + *endl_pos) = '\0';
	*line = tmpstr;
	tmpstr = (char *)malloc(data->prestr_len - *endl_pos);
	if (!tmpstr)
		return (-1);
	ft_memmove(tmpstr, (data->prestr + *endl_pos + 1), \
		(data->prestr_len - *endl_pos - 1));
	*(tmpstr + data->prestr_len - *endl_pos - 1) = '\0';
	free(data->prestr);
	data->prestr = tmpstr;
	data->prestr_len = data->prestr_len - *endl_pos - 1;
	return (1);
}

static	int	add_worker(long bytes_read, t_gnl_data *data)
{
	char				*tmpstr;

	tmpstr = (char *)malloc(data->prestr_len + bytes_read + 1);
	if (!tmpstr)
		return (-1);
	if (data->prestr)
		ft_memmove(tmpstr, data->prestr, data->prestr_len);
	ft_memmove((tmpstr + data->prestr_len), data->buf, bytes_read);
	*(tmpstr + data->prestr_len + bytes_read) = '\0';
	if (data->prestr)
		free(data->prestr);
	data->prestr = tmpstr;
	data->prestr_len = data->prestr_len + bytes_read;
	return (0);
}

static	int	newline_worker(long bytes_read, t_gnl_data *data, \
	int endl_pos, char **line)
{
	char				*tmpstr;

	tmpstr = (char *)malloc(data->prestr_len + endl_pos + 1);
	if (!tmpstr)
		return (-1);
	if (data->prestr)
		ft_memmove(tmpstr, data->prestr, data->prestr_len);
	ft_memmove((tmpstr + data->prestr_len), data->buf, endl_pos);
	*(tmpstr + data->prestr_len + endl_pos) = '\0';
	if (data->prestr)
		free(data->prestr);
	data->prestr = (char *)malloc(bytes_read - endl_pos);
	if (!data->prestr)
		return (-1);
	ft_memmove(data->prestr, data->buf + endl_pos + 1, \
		(bytes_read - endl_pos - 1));
	*(data->prestr + bytes_read - endl_pos - 1) = '\0';
	data->prestr_len = bytes_read - endl_pos - 1;
	*line = tmpstr;
	return (1);
}

static	int	gnl_worker(t_gnl_data *data, int fd, char **line)
{
	long				bytes_read;
	int					endl_pos;

	if (data->prestr != NULL && ft_strchrpos(data->prestr, '\n') >= 0)
		return (data_worker(data, &endl_pos, line));
	bytes_read = read(fd, data->buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		data->buf[bytes_read] = '\0';
		endl_pos = ft_strchrpos(data->buf, '\n');
		if (endl_pos < 0 && add_worker(bytes_read, data) < 0)
			return (-1);
		if (endl_pos >= 0)
			return (newline_worker(bytes_read, data, endl_pos, line));
		bytes_read = read(fd, data->buf, BUFFER_SIZE);
	}
	if (gnl_void_or_error(bytes_read, data) < 0)
		return (-1);
	*line = data->prestr;
	data->prestr = NULL;
	data->prestr_len = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_data	data;
	int					ret;

	if (fd == -42)
	{
		free(data.prestr);
		return (0);
	}
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	data.buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!data.buf)
		return (-1);
	ret = gnl_worker(&data, fd, line);
	free(data.buf);
	return (ret);
}
