# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 22:13:23 by bsouchet          #+#    #+#              #
#    Updated: 2017/05/13 20:58:43 by lgatibel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C			= clang

NAME		= rt

FLAGS		= -Wall -Wextra -Werror -g

OPENCL_F	= -framework OpenCL

SDL2_F		= -framework SDL2 -framework SDL2_ttf -framework SDL2_image  -F ./frameworks/

SDL2_P		= -rpath @loader_path/frameworks/

SDL2_I		= -I ./frameworks/SDL2.framework/Headers

SDL2_TTF_I	= -I ./frameworks/SDL2_ttf.framework/Headers

SDL2_IMG_I	= -I ./frameworks/SDL2_image.framework/Headers

FSDL		= libraries/fsdl

LIBFT		= libraries/libft

LIBGNL		= libraries/libgnl

LIBVECT		= libraries/libvect

LIBCL		= libraries/libcl

LIBFMT		= libraries/libfmt

DIR_S		= sources

DIR_O		= temporary

IMG_DIR		= saved_images

HEADER		= include \
			libraries/libft/include \
			libraries/libvect/include \
			libraries/libgnl/include \
			libraries/libcl/include \
			libraries/libfmt/include

# Compilation options
BENCHMARK_KRL	?=	0

SOURCES		= \
 		cl_build/cl_copy_image_buffer.c \
		cl_build/cl_main_krl_exec.c \
		cl_build/cl_main_krl_init.c \
		cl_build/cl_main_krl_update_buffers.c \
		cl_build/cl_main_krl_update_camera.c \
		cl_build/cpy_cam.c \
		cl_build/cpy_lgt.c \
		cl_build/cpy_obj.c \
		cluster/cluster_init.c \
		cluster/cluster_send_command.c \
		cluster/cluster_strategy.c \
		export/cameras.c \
		export/export_config.c \
		export/lights.c \
		export/objects.c \
		gui/draw_button.c \
		gui/draw_case_box.c \
		gui/draw_current_camera_name.c \
		gui/draw_dimensions_parameters.c \
		gui/draw_info_and_state.c \
		gui/draw_materials.c \
		gui/draw_outliner.c \
		gui/draw_outliner_elements.c \
		gui/draw_outliner_nav_buttons.c \
		gui/draw_panels.c \
		gui/draw_scene_parameters.c \
		gui/draw_selected_element.c \
		gui/draw_selected_panel.c \
		gui/draw_special_mode.c \
		gui/init_buttons.c \
		gui/init_structures.c \
		gui/init_structures_selected_element.c \
		gui/save_to_png.c \
		handle/buttons.c \
		handle/delete_element.c \
		handle/elements.c \
		handle/errors.c \
		handle/events.c \
		handle/info_bar.c \
		handle/keyboard.c \
		handle/linked_lists.c \
		handle/mouse.c \
		handle/mouse_clicks.c \
		handle/outliner.c \
		handle/scene_parameters.c \
		handle/se_box.c \
		handle/se_box_minus.c \
		handle/se_box_plus.c \
		handle/selected_element.c \
		handle/shaders.c \
		handle/special_mode.c \
		main.c \
		misc/free_elements.c \
		parser/add_elements.c \
		parser/add_elements_parameters.c \
		parser/check_elements.c \
		parser/check_tags.c \
		parser/clear_buffer.c \
		parser/get_informations.c \
		parser/get_numbers.c \
		parser/get_type_elements.c \
		parser/init_global_stuctures.c \
		parser/set_elements_parameters.c \
		renderer/init_renderer.c \
		renderer/start_renderer.c \
		special_modes/cartoon.c \
		special_modes/greyscale.c \
		special_modes/pixel_art.c \
		special_modes/reverse.c \
		special_modes/saturate.c \
		special_modes/sepia.c \
		special_modes/sobel.c

SUB_FOLDERS	= gui handle misc parser renderer special_modes cl_build export cluster

BUILD_DIR	= $(addprefix $(DIR_O)/,$(SUB_FOLDERS))

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

opti:
	@$(MAKE) all

all: temporary $(NAME)

$(NAME): $(OBJS)
	@make -C $(FSDL)
	@make -C $(LIBFT)
	@make -C $(LIBVECT)
	@make -C $(LIBGNL)
	@make -C $(LIBCL)
	@make -C $(LIBFMT)
	@echo "                           \033[34mcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "                          \033[34m/ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "                          \033[34mccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "                          \033[34mccccc\033[36m.................................................................\033[34m::ccccccccccccccccccccccccccccccc\033[0m"
	@echo "                         \033[34m/ccccc\033[36m.........................................................................\033[34m:cccccccccccccccccccccccccccc\033[0m"
	@echo "                         \033[34mccccc:\033[36m...............................................................................\033[34mccccccccccccccccccccccccc\033[0m"
	@echo "                         \033[34mccccc\033[36m...................................................................................\033[34mcccccccccccccccccccccccc\033[0m"
	@echo "                        \033[34m/ccccc\033[36m......................................................................................\033[34mooccccccccccccccccccccc\033[0m"
	@echo "                        \033[34mcccccc\033[36m........................................................................................\033[34m:oooccccccccccccccccccc\033[0m"
	@echo "                        \033[34mccccc\033[36m...........................................................................................\033[34mcooooccccccccccccccccc\033[0m"
	@echo "                       \033[34m/ccccc\033[36m............................................................................................\033[34m:ooooooccccccccccccccc\033[0m"
	@echo "                       \033[34mccccc:\033[36m..............................................................................................\033[34mooooooccccccccccccccc\033[0m"
	@echo "                       \033[34mccccc\033[36m................................................................................................\033[34mooooooocccccccccccccc\033[0m"
	@echo "                      \033[34m/ccccc\033[36m................................................................................................\033[34m:ooooooocccccccccccccc\033[0m"
	@echo "                      \033[34mccccc:\033[36m..........................:::::::::::::::........................................................\033[34mcoooooocccccccccccccc\033[0m"
	@echo "                      \033[34mccccc\033[36m...........................\033[34mooooooooooococcccccccccccccccccccc:\033[36m.....................................\033[34moooooooccccccccccccc\033[0m"
	@echo "                     \033[34m/ccccc\033[36m..........................\033[34mcoooooooooocccccccccccccccccccccccccccc:\033[36m.................................\033[34mooooooooccccccccccccc\033[0m"
	@echo "                     \033[34mccccc:\033[36m..........................\033[34mooooooooooccccccccccc      ~:ccccccccccccc\033[36m...............................\033[34mooooooooocccccccccccc\033[0m"
	@echo "                     \033[34mccccc\033[36m..........................\033[34m:oooooooooocccccccccc               cccccccc:\033[36m.............................\033[34mooooooooocccccccccccc\033[0m"
	@echo "                    \033[34m/cccc:\033[36m..........................\033[34moooooooooocccccccccc:                  ccccccc\033[36m............................\033[34mooooooooccccccccccccc\033[0m"
	@echo "                    \033[34mccccc\033[36m...........................\033[34moooooooooccccccccccc                    :ccccc:\033[36m...........................\033[34mooooooooocccccccccccc\033[0m"
	@echo "                    \033[34mccccc\033[36m..........................\033[34m:oooooooooccccccccccc                     ccccc:\033[36m...........................\033[34mooooooooocccccccccccc\033[0m"
	@echo "                   \033[34m/ccccc\033[36m..........................\033[34moooooooooocccccccccc:                     ccccc:\033[36m...........................\033[34moooooooocccccccccccc\033[0m"
	@echo "                   \033[34mccccc:\033[36m..........................\033[34moooooooooocccccccccc                     .ccccc\033[36m...........................\033[34mcoooooooocccccccccccc\033[0m"
	@echo "                   \033[34mccccc\033[36m..........................\033[34mcoooooooooccccccccccc                     cccccc\033[36m...........................\033[34mooooooooccccccccccccc\033[0m"
	@echo "                  \033[34m/cccc:\033[36m..........................\033[34moooooooooocccccccccc                     cccccc\033[36m...........................\033[34mooooooooccccccccccccc\033[0m"
	@echo "                  \033[34mccccc\033[36m...........................\033[34moooooooooocccccccccc                   ccccccc\033[36m...........................\033[34mcooooooocccccccccccccc\033[0m"
	@echo "                  \033[34mccccc\033[36m..........................\033[34m:ooooooooooccccccccc:                 cccccccc\033[36m............................\033[34mooooooocccccccccccccc\033[0m"
	@echo "                 \033[34m/ccccc\033[36m..........................\033[34moooooooooooccccccccc               cccccccccc\033[36m............................\033[34mooooooocccccccccccccc\033[0m"
	@echo "                 \033[34mccccc\033[36m...........................\033[34moooooooooooccccccccc      .:cccccccccccccc\033[36m..............................\033[34mooooooccccccccccccccc\033[0m"
	@echo "                 \033[34mccccc\033[36m..........................\033[34moooooooooooocccccccccccccccccccccccccccc:\033[36m..............................\033[34m:ooooooccccccccccccccc\033[0m"
	@echo "                \033[34m/cccc:\033[36m..........................\033[34mooooooooooooocccccccccccccccccccccc:\033[36m..................................\033[34m:ooooccocccccccccccccc\033[0m"
	@echo "                \033[34mccccc\033[36m................................................................................................\033[34moooooccccccccccccccccc\033[0m"
	@echo "                \033[34mccccc\033[36m..............................................................................................\033[34m:oooccccccccccccccccccc\033[0m"
	@echo "               \033[34m/cccc\033[36m..............................................................................................\033[34moococccccccccccccccccc\033[0m"
	@echo "               \033[34mccccc\033[36m...........................................................................................\033[34m:oococccccccccccccccccc\033[0m"
	@echo "               \033[34mccccc\033[36m.........................................................................................\033[34mcoococcccccccccccccccccc\033[0m"
	@echo "              \033[34m/cccc:\033[36m.......................................................................................\033[34mooococcccccccccccccccccc\033[0m"
	@echo "              \033[34mccccc\033[36m.....................................................................................\033[34m:ooooccccccccccccccccccc\033[0m"
	@echo "              \033[34mccccc\033[36m..................................................................................\033[34mcoooooocccccccccccccccccc\033[0m"
	@echo "             \033[34m/cccc\033[36m................................................................................\033[34mooooooooocccccccccccccccc\033[0m"
	@echo "             \033[34mccccc\033[36m...........................................................................\033[34m:oooooooooooocccccccccccccc\033[0m"
	@echo "             \033[34mccccc\033[36m...........................................................................\033[34moooooooooooooccccccccccc\033[0m"
	@echo "            \033[34m/cccc:\033[36m............................................................................\033[34mooooooooooooccccccccc\033[0m"
	@echo "            \033[34mccccc\033[36m..........................\033[34m:ooooooooooococcccccccc\033[36m.............................\033[34mooooooooooocccccccccc\033[0m"
	@echo "            \033[34mcccc:\033[36m..........................\033[34moooooooooooccccccccccccc\033[36m.............................\033[34mooooooooooocccccccccc\033[0m"
	@echo "           \033[34m/cccc\033[36m...........................\033[34mooooooooooccccccccccccccc\033[36m.............................\033[34moooooooooooccccccccccc\033[0m"
	@echo "           \033[34mccccc\033[36m..........................\033[34mooooooooooccccccccccccccccc\033[36m..............................\033[34mooooooooooccccccccccccccccc\033[0m"
	@echo "           \033[34mcccc:\033[36m..........................\033[34mooooooooooccccccccc/ :ccccc:\033[36m..............................\033[34mooooooooooccccccccccccccccccccc\033[0m"
	@echo "          \033[34m/cccc\033[36m...........................\033[34mooooooooooccccccccc   cccccc:\033[36m..............................\033[34mooooooooooccccccccccccccccccccc\033[0m"
	@echo "          \033[34mccccc\033[36m..........................\033[34moooooooooccccccccccc    :cccccc\033[36m........................................\033[34m:cccccccccccccccccccc\033[0m"
	@echo "          \033[34mcccc:\033[36m..........................\033[34mooooooooocccccccccc/     :ccccc:\033[36m........................................\033[34moocccccccccccccccccc\033[0m"
	@echo "         \033[34m/cccc\033[36m..........................\033[34moooooooooocccccccccc       cccccc:\033[36m.......................................\033[34moooccccccccccccccccc\033[0m"
	@echo "         \033[34mccccc\033[36m..........................\033[34moooooooooccccccccccc        :ccccc:\033[36m......................................\033[34moooocccccccccccccccc\033[0m"
	@echo "         \033[34mcccc:\033[36m..........................\033[34mooooooooccccccccccc/         cccccc:\033[36m.....................................\033[34moooocccccccccccccccc\033[0m"
	@echo "        \033[34m/cccc\033[36m..........................\033[34moooooooooccccccccccc           cccccc:\033[36m....................................\033[34moooocccccccccccccccc\033[0m"
	@echo "        \033[34mccccc\033[36m..........................\033[34moooooooocccccccccccc            cccccc\033[36m....................................\033[34moooocccccccccccccccc\033[0m"
	@echo "        \033[34mcccc:\033[36m.........................\033[34mcooooooocccccccccccc/             cccccc:\033[36m.................................\033[34mooooccccccccccccccccc\033[0m"
	@echo "       \033[34m/cccc\033[36m..........................\033[34moooooccccccccccccccc               cccccc\033[36m................................\033[34mooocccccccccccccccccc\033[0m"
	@echo "       \033[34mccccc\033[36m.........................\033[34mccocccccccccccccccccc                cccccc:\033[36m.............................\033[34moccoccccccccccccccccc\033[0m"
	@echo "       \033[34mcccc:\033[36m.........................\033[34mcccccccccccccccccccc                  ccccccc\033[36m...........................\033[34mccccccccccccccccccccc\033[0m"
	@echo "      \033[34m/cccc\033[36m..........................\033[34mcccccccccccccccccccc                   .cccccc\033[36m.......................\033[34mccccccccccccccccccccccc\033[0m"
	@echo "      \033[34mcccc:\033[36m.........................\033[34m:ccccccccccccccccccc/                    .cccccccc\033[36m................\033[34m:cccccccccccccccccccccccc\033[0m"
	@echo "     \033[34m.cccccccccccccccccccccccccccccccccccccccccccccccccc                      .ccccccccccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "     \033[34m.cccccccccccccccccccccccccccccccccccccccccccccccccc                       .cccccccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "     \033[34mCccccccccccccccccccccccccccccccccccccccccccccccccc/                        .ccccccccccccccccccccccccccccccccccccccc\033[0m"
	@echo "     \033[34m.cccccccccccccccccccccccccccccccccccccccccccccccc/                          .ccccccccccccccccccccccccccccccccccc\033[0m\n\n"
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -L $(FSDL) -lfsdl -lpthread -L $(LIBVECT) -lvect -L $(LIBFMT) -lfmt -L $(LIBGNL) -lgnl -L $(LIBCL) -lcl -o $@ $^ $(OPENCL_F) $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

temporary: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -D BENCHMARK_KRL=$(BENCHMARK_KRL) $(addprefix -I, $(HEADER)) -c -o $@ $<

norme:
	@make norme -C $(LIBFT)
	@make norme -C $(LIBVECT)
	@make norme -C $(LIBGNL)
	@make norme -C $(LIBCL)
	@make norme -C $(LIBFMT)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	@make clean -C $(FSDL)
	@make clean -C $(LIBFT)
	@make clean -C $(LIBVECT)
	@make clean -C $(LIBGNL)
	@make clean -C $(LIBCL)
	@make clean -C $(LIBFMT)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FSDL)
	@make fclean -C $(LIBFT)
	@make fclean -C $(LIBVECT)
	@make fclean -C $(LIBGNL)
	@make fclean -C $(LIBCL)
	@make fclean -C $(LIBFMT)

delimg: fclean
	@rm -rf $(IMG_DIR)

re: fclean
	@$(MAKE) all

r: $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -L $(FSDL) -lfsdl -lpthread -L $(LIBVECT) -lvect -L $(LIBFMT) -lfmt -L $(LIBGNL) -lgnl -L $(LIBCL) -lcl -o $(NAME) $^ $(OPENCL_F) $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

benchmark_krl: $(OBJS)
	rm temporary/cl_build/cl_main_krl_exec.o
	BENCHMARK_KRL=1 make

.PHONY: all, temporary, norme, clean, fclean, re
