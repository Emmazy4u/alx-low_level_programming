#include "main.h"

/**
 * append_text_to_file - Would Append text at tail end of a file.
 * @filename: points at the file name
 * @text_content: String to be added to the file file.
 *
 * Return: NULL function or filenname failure (- -1),
 *         If the file doesn't exist, user would lack write permissions (- -1).
 *        Otherwise (- 1).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);
	close(o);
	return (1);
}
