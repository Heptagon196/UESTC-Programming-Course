#include "Config.h"

void edit_config(SnakeGameData* data) {
    int option = 0;
    while (true) {
        char option_map_file[256];
        char option_rank_file[256];
        char option_snake_speed[256];
        char option_additional_food_lasting_time[256];
        char option_additional_food_generate_time[256];
        char option_eraser_possibility[256];

        sprintf(option_map_file, "Map file: %25s", data->map_filename);
        sprintf(option_rank_file, "Rank file: %24s", data->rank_filename);
        sprintf(option_snake_speed, "Snake speed: %22.2lf", data->speed);
        sprintf(option_additional_food_lasting_time, "Extra food existing time: %9d", data->additional_food_lasting_time);
        sprintf(option_additional_food_generate_time, "Extra food generation time: %7d", data->additional_food_generate_time);
        sprintf(option_eraser_possibility, "Eraser generation: %16.2lf", data->eraser_possibility);

        option = Menu(7, option, "Settings", (const char*[]){option_map_file, option_rank_file, option_snake_speed, option_additional_food_lasting_time, option_additional_food_generate_time, option_eraser_possibility, "Back"});

        if (option == -1 || option == 6) {
            clear_screen();
            return ;
        }
        if (option == 0) {
            char* s = input_box(21, 1, data->map_filename, (const char*[]){"Set path to the map:"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    strcpy(data->map_filename, s);
                }
                free(s);
            }
        }
        if (option == 1) {
            char* s = input_box(21, 1, data->rank_filename, (const char*[]){"Set path to the rank file:"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    strcpy(data->rank_filename, s);
                }
                free(s);
            }
        }
        if (option == 2) {
            char* s = input_box(21, 2, "", (const char*[]){"Set the number of blocks", "the snake moves per second:"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    sscanf(s, "%lf", &data->speed);
                }
                free(s);
            }
        }
        if (option == 3) {
            char* s = input_box(21, 1, "", (const char*[]){"Set a time limit for extra food:"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    sscanf(s, "%d", &data->additional_food_lasting_time);
                }
                free(s);
            }
        }
        if (option == 4) {
            char* s = input_box(21, 2, "", (const char*[]){"Set the time between", "the generation of extra food:"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    sscanf(s, "%d", &data->additional_food_generate_time);
                }
                free(s);
            }
        }
        if (option == 5) {
            char* s = input_box(21, 2, "", (const char*[]){"Set the possibility of", "the generation of eraser"});
            if (s != NULL) {
                if (strlen(s) > 0) {
                    sscanf(s, "%lf", &data->eraser_possibility);
                }
                free(s);
            }
        }
    }
}

void save_config(SnakeGameData* data, const char* config_filename) {
    FILE* fp = fopen(config_filename, "w");
    fprintf(fp, "map_file=%s\n", data->map_filename);
    fprintf(fp, "rank_file=%s\n", data->rank_filename);
    fprintf(fp, "snake_speed=%lf\n", data->speed);
    fprintf(fp, "additional_food_lasting_time=%d\n", data->additional_food_lasting_time);
    fprintf(fp, "additional_food_generate_time=%d\n", data->additional_food_generate_time);
    fprintf(fp, "eraser_possibility=%lf\n", data->eraser_possibility);
    fclose(fp);
}
