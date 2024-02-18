.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

ifdef DEBUG
		CFLAGS += -O0 -g -fsanitize=address,undefined
endif

link_files:: unlink_files
		@mkdir -p $(dst_dir);
		$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
		$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)