#include "../include/libft.h"

int	gnl_void_or_error(int bytes_read, t_gnl_data *data)
{
	if (bytes_read < 0)
		return (-1);
	if (data->prestr_len == 0 && data->prestr == NULL)
	{
		data->prestr = (char *)malloc(1);
		if (!data->prestr)
			return (-1);
		*(data->prestr) = '\0';
	}
	return (0);
}
