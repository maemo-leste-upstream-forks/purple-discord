#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "imgstore.h"

#define PurpleImage  PurpleStoredImage
#define purple_image_new_from_file(p, e)  purple_imgstore_new_from_file(p)
#define purple_image_new_from_data(d, l)  purple_imgstore_add(d, l, NULL)
#define purple_image_get_path             purple_imgstore_get_filename
#define purple_image_get_data_size        purple_imgstore_get_size
#define purple_image_get_data             purple_imgstore_get_data
#define purple_image_get_extension        purple_imgstore_get_extension


static inline const gchar *
purple_image_get_mimetype(PurpleImage *image)
{
	const gchar *extension = purple_image_get_extension(image);

	if (purple_strequal(extension, "jpg") || purple_strequal(extension, "jpeg")) {
		return "image/jpeg";
	} else if (purple_strequal(extension, "png")) {
		return "image/png";
	} else if (purple_strequal(extension, "gif")) {
		return "image/gif";
	}
	return "image/*";
}

#endif /* _IMAGE_H_ */
