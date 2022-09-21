#include "splashkit.h"
#include <vector>

using namespace std;
using std::vector;

#define PLAYER_SPEED 5
#define OBSTACLE_SPEED 6

// Progam Demonstration: https://video.deakin.edu.au/media/t/1_tl5pczcy
// Code Walkthrough: https://video.deakin.edu.au/media/t/1_n4t9493r

// player model colour options
enum colour_option
{
    RED, // red player model
    BLUE, // blue player model
    GREEN // green player model
};
// struct containing player data: sprite, colour, live, invincibility.
struct player_data
{
    sprite player_sprite; // player sprite
    colour_option player_colour; // player colour based on enumeration
    int lives;  // amount of lives player has
    bool invincibility; // whether player is invincible or not
};
// struct containing obstacle data: sprite
struct obstacle_data
{
    sprite obstacle_sprite; // obstacle sprite
};
// struct containing wall data: sprite
struct wall_data
{
    sprite wall_sprite; // wall sprite
};
// struct containing level data: level number, teleporter sprite, button sprite, obstacles vector, walls vector.
struct level_data
{
    int level_number; // level's number
    sprite teleporter_sprite; // teleporter sprite
    sprite button_sprite; // button sprite
    vector<obstacle_data>obstacle; // vector of obstacles
    vector<wall_data>wall; // vector of walls
};
// struct containing game data: player data, level data, current level number.
struct game_data
{
    player_data player; // data for player
    int current_level; // current levels number
    vector<level_data>level; // vector of level designs
};
// loads resource bundle containing sprites
void load_resources()
{
    load_resource_bundle("game_bundle", "must_escape.txt"); // loads text file indicating the names of bitmaps in the directory
}
// creates sprite for an obstacle and places it in position
obstacle_data create_obstacle_level_1(int index)
{
    obstacle_data result;
    
    // creates sprite
    result.obstacle_sprite = create_sprite("blue_obstacle");

    // creates three obstacles at different starting locations and directions based on whether they start at top or bottom of screen
    if(index == 0)
    {
        sprite_set_x(result.obstacle_sprite, 400);
        sprite_set_y(result.obstacle_sprite, 0); 
        sprite_set_dy(result.obstacle_sprite, OBSTACLE_SPEED);
    }
    else if(index == 1)
    {
        sprite_set_x(result.obstacle_sprite, 800);
        sprite_set_y(result.obstacle_sprite, 750); 
        sprite_set_dy(result.obstacle_sprite, -1 * OBSTACLE_SPEED);
    }
    else if(index == 2)
    {
        sprite_set_x(result.obstacle_sprite, 1200);
        sprite_set_y(result.obstacle_sprite, 0); 
        sprite_set_dy(result.obstacle_sprite, OBSTACLE_SPEED);
    }

    return result;
}
// creates sprite for an obstacle and places it in position
obstacle_data create_obstacle_level_2(int index)
{
    obstacle_data result;
    
    // creates obstacle sprite
    result.obstacle_sprite = create_sprite("blue_obstacle");

    // creates four obstacles at different starting locations and directions based on whether they start at top or bottom of screen 
    if(index == 0)
    {
        sprite_set_x(result.obstacle_sprite, 350);
        sprite_set_y(result.obstacle_sprite, 0); 
        sprite_set_dy(result.obstacle_sprite, OBSTACLE_SPEED);
    }
    else if(index == 1)
    {
        sprite_set_x(result.obstacle_sprite, 550);
        sprite_set_y(result.obstacle_sprite, 750); 
        sprite_set_dy(result.obstacle_sprite, -1 * OBSTACLE_SPEED);
    }
    else if(index == 2)
    {
        sprite_set_x(result.obstacle_sprite, 1050);
        sprite_set_y(result.obstacle_sprite, 0); 
        sprite_set_dy(result.obstacle_sprite, OBSTACLE_SPEED);
    }
    else if(index == 3)
    {
        sprite_set_x(result.obstacle_sprite, 1150);
        sprite_set_y(result.obstacle_sprite, 650); 
        sprite_set_dx(result.obstacle_sprite, -1 * OBSTACLE_SPEED);
    }

    return result;
}
// creates sprite for an obstacle and places it in position
obstacle_data create_obstacle_level_3(int i, int index)
{
    obstacle_data result;
    
    // creates obstacle sprite
    result.obstacle_sprite = create_sprite("blue_obstacle");

    // creates 20 obstacles that are moved to the right by 75 pixels each iteration
    sprite_set_x(result.obstacle_sprite, index);
    sprite_set_y(result.obstacle_sprite, 0); 
    sprite_set_dy(result.obstacle_sprite, OBSTACLE_SPEED);

    return result;
}
// creates sprite for wall and places it in position
wall_data create_wall_level_2(int index)
{
    wall_data result;

    // creates wall sprite using different wall sizes and positions them to create level
    switch (index)
    {
    case 0:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 200);
        sprite_set_y(result.wall_sprite, 0); 
    break;
    case 1:
        result.wall_sprite = create_sprite("wall_2");
        sprite_set_x(result.wall_sprite, 250);
        sprite_set_y(result.wall_sprite, 250); 
    break;
    case 2:
        result.wall_sprite = create_sprite("wall_3");
        sprite_set_x(result.wall_sprite, 400);
        sprite_set_y(result.wall_sprite, 250); 
    break;
    case 3:
        result.wall_sprite = create_sprite("wall_4");
        sprite_set_x(result.wall_sprite, 600);
        sprite_set_y(result.wall_sprite, 250); 
    break;    
    case 4:
        result.wall_sprite = create_sprite("wall_2");
        sprite_set_x(result.wall_sprite, 1100);
        sprite_set_y(result.wall_sprite, 250); 
    break;    
    case 5:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 1200);
        sprite_set_y(result.wall_sprite, 0); 
    break;    
    case 6:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 200);
        sprite_set_y(result.wall_sprite, 500); 
    break;    
    case 7:
        result.wall_sprite = create_sprite("wall_2");
        sprite_set_x(result.wall_sprite, 250);
        sprite_set_y(result.wall_sprite, 500); 
    break;    
    case 8:
        result.wall_sprite = create_sprite("wall_3");
        sprite_set_x(result.wall_sprite, 400);
        sprite_set_y(result.wall_sprite, 500); 
    break;    
    case 9:
        result.wall_sprite = create_sprite("wall_2");
        sprite_set_x(result.wall_sprite, 600);
        sprite_set_y(result.wall_sprite, 500);
    break;    
    case 10:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 700);
        sprite_set_y(result.wall_sprite, 500); 
    break;    
    case 11:
        result.wall_sprite = create_sprite("wall_3");
        sprite_set_x(result.wall_sprite, 900);
        sprite_set_y(result.wall_sprite, 500);
    break;    
    case 12:
        result.wall_sprite = create_sprite("wall_2");
        sprite_set_x(result.wall_sprite, 1100);
        sprite_set_y(result.wall_sprite, 500);
    break;    
    case 13:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 1200);
        sprite_set_y(result.wall_sprite, 500);
    break;    
    case 14:
        result.wall_sprite = create_sprite("wall_1");
        sprite_set_x(result.wall_sprite, 1250);
        sprite_set_y(result.wall_sprite, 250);
    break;     
    }
    return result;
}
// returns bitmap based on enumeration input
bitmap player_bitmap(colour_option colour)
{
    switch (colour)
    {
    case BLUE:
        return bitmap_named("blue_player"); //return blue player model bitmap
    case GREEN:
        return bitmap_named("green_player"); //return green player model bitmap
    default:
        return bitmap_named("red_player"); //return red player model bitmap which is default option
    }
}
// shows and hides player model layers to change colour
void player_switch_colour(player_data &player, colour_option target)
{
    // inputs are current player colour and target player colour and if they are not the same hides current layer and shows target layer
    if (player.player_colour != target)
    {
        sprite_show_layer(player.player_sprite, static_cast<int>(target));
        sprite_hide_layer(player.player_sprite, static_cast<int>(player.player_colour));

        player.player_colour = target;
    }
}
// creaters player with sprite, lives, invicibility status and position
player_data create_player()
{
    player_data result;
    bitmap default_bitmap = player_bitmap(RED);

    // creates player sprite, assigns starting lives and invincibility status set to false
    result.player_sprite = create_sprite(default_bitmap);
    result.lives = 3;
    result.invincibility = false;

    // adds sprite layers for alternative player model colours
    sprite_add_layer(result.player_sprite, player_bitmap(BLUE), "blue_player");
    sprite_add_layer(result.player_sprite, player_bitmap(GREEN), "green_player");

    // hides new layers so only one is seen
    sprite_hide_layer(result.player_sprite, 1);
    sprite_hide_layer(result.player_sprite, 2);

    // sets default colour
    result.player_colour = RED;

    // sets player start position
    sprite_set_x(result.player_sprite, 50);
    sprite_set_y(result.player_sprite, (screen_height() - sprite_height(result.player_sprite))/2);

    return result;
}
// draws player sprite to screen
void draw_player(const player_data &player_to_draw)
{
    // draws player sprite to screen at previously set position
    draw_sprite(player_to_draw.player_sprite);
}
// updates player movement and stops movement when hitting wall
void update_player(player_data &player_to_update)
{   
    // updates player movement
    update_sprite(player_to_update.player_sprite);

    bool top, bot, left, right;

    // x and y value depicting center of player sprite
    point_2d sprite_center = center_point(player_to_update.player_sprite);

    // boolean values to determine if player is hitting border of window/outer wall
    bot = (sprite_center.y - 25) < 0;
    top = (sprite_center.y + 25) > 800;
    right = (sprite_center.x - 25) < 0;
    left = (sprite_center.x + 25) > 1600;

    // based on what side of border player is hitting the player is moved back into area of play
    if(top == true)
    {
        sprite_set_y(player_to_update.player_sprite, 750);
    }
    if(bot == true)
    {
        sprite_set_y(player_to_update.player_sprite, 0);
    }
    if(right == true)
    {
        sprite_set_x(player_to_update.player_sprite, 0);
    }
    if(left == true)
    {
        sprite_set_x(player_to_update.player_sprite, 1550);
    }
}
// makes player move on arrow key press and stops movement on release
void handle_input(player_data &player)
{
    // down arrow key moves player sprite down and stops moving when key is released
    if (key_down(DOWN_KEY))
        sprite_set_dy(player.player_sprite, PLAYER_SPEED);
    if (key_released(DOWN_KEY))
        sprite_set_dy(player.player_sprite, 0);

    // up arrow key moves player sprite up and stops moving when key is released
    if (key_down(UP_KEY))
        sprite_set_dy(player.player_sprite, 0 - PLAYER_SPEED);
    if (key_released(UP_KEY))
        sprite_set_dy(player.player_sprite, 0);  

    // left arrow key moves player sprite left and stops moving when key is released
    if (key_down(LEFT_KEY))
        sprite_set_dx(player.player_sprite, 0 - PLAYER_SPEED);
    if (key_released(LEFT_KEY))
        sprite_set_dx(player.player_sprite, 0);

    // right arrow key moves player sprite right and stops moving when key is released
    if (key_down(RIGHT_KEY))
        sprite_set_dx(player.player_sprite, PLAYER_SPEED);
    if (key_released(RIGHT_KEY))
        sprite_set_dx(player.player_sprite, 0);     
}
// sets button sprite position
void draw_button(sprite button)
{
    // sets x and y postion of button sprite
    sprite_set_x(button, 1150);
    sprite_set_y(button, 750);
}
// sets teleporter sprite position
void draw_teleporter(sprite teleporter)
{
    // sets sprite postion of teleporter
    sprite_set_x(teleporter, 1500);
    sprite_set_y(teleporter, (screen_height() - sprite_height(teleporter))/2);
}
// draws obstacle to screen
void draw_obstacle(const obstacle_data &obstacle)
{
    // draws sprite of obstacle input to screen
    draw_sprite(obstacle.obstacle_sprite);
}
// draws all obstacles to screen as well as button and teleporter
void draw_obstacles(level_data level)
{
    // iterates through obstacles in vector and draws them to screen
    for(int i = 0; i < level.obstacle.size(); i++)
    {
        draw_obstacle(level.obstacle[i]);
    }

    // draws teleporter sprite to screen
    draw_sprite(level.teleporter_sprite);

    // draws button to screen if it is level 2
    if(level.level_number == 2)
    {
        draw_sprite(level.button_sprite);
    }
}
// draws wall sprite to screen
void draw_wall(const wall_data &wall)
{
    // draws wall sprite to screen
    draw_sprite(wall.wall_sprite);
}
// draws all wall sprites to screen
void draw_walls(level_data level)
{
    // iterates through wall vector drawing all to screen
    for(int i = 0; i < level.wall.size(); i++)
    {
        draw_wall(level.wall[i]);
    }
}
// draws amount of lives player has to top left of screen as heart sprite
void draw_lives(player_data player)
{
    // draws heart bitmap to top left of the screen as many times as the player has lives moving to right every iteration
    int index = 5;
    for(int i = 0; i < player.lives; i++)
    {
        draw_bitmap("lives", index, 0);
        index = index + 60;
    }
}
// draws text to screen giving player instructions and hints
void draw_message(game_data game)
{
    // draws text hint on level 1 instructing player how to play
    if(game.current_level == 0)
    {
        draw_text("reach the teleporter without getting hit.", COLOR_WHITE, 25,325);
    }
    // draws text making joke and giving hint for level 2
    else if(game.current_level == 1)
    {
        draw_text("that was a practice this levels much harder..", COLOR_WHITE, 25,325);
        draw_text("try the button.", COLOR_WHITE, 1125,725);
    }
    // draws text making another joke and gives hint of how to beat level
    else if(game.current_level == 2)
    {
        draw_text("okay sure that level wasn't that hard. good lucky with this one :)", COLOR_WHITE, 25,200);
        if(game.player.lives == 1)
        {
            draw_text("try hitting space bar if you need help so bad..", COLOR_WHITE, 25,225);
        }
    }
}
// updates obstacle movement and reverses its movement after colliding with wall
void update_obstacle(obstacle_data &obstacle)
{
    // updates obstacle movement
    update_sprite(obstacle.obstacle_sprite);

    bool top, bot, left, right;

    // x and y location of obstacle sprite center
    point_2d sprite_center = center_point(obstacle.obstacle_sprite);

    // boolean values to determine if obstacle is hitting border of window/outer wall
    bot = (sprite_center.y - 25) < 0;
    top = (sprite_center.y + 25) > 800;
    right = (sprite_center.x - 25) < 0;
    left = (sprite_center.x + 25) > 1600;

    // based on what side of border obstacle is hitting the obstacles reverses its direction of movement (bounces off wall)
    if(top == true)
    {
        sprite_set_dy(obstacle.obstacle_sprite, -1 * OBSTACLE_SPEED);
    }
    if(bot == true)
    {
        sprite_set_dy(obstacle.obstacle_sprite, OBSTACLE_SPEED);
    }
    if(left == true)
    {
        sprite_set_dx(obstacle.obstacle_sprite, -1 * OBSTACLE_SPEED);
    }
    if(right == true)
    {
        sprite_set_dx(obstacle.obstacle_sprite, OBSTACLE_SPEED);
    }
}
// updates all obstacles movement
void update_obstacles(level_data level)
{
    // iterates through obstacles updating movement
    for(int i = 0; i < level.obstacle.size(); i++)
    {
       update_obstacle(level.obstacle[i]);
    }
}
// draws game over screen
void draw_end_screen()
{
    // draws screen showing game over
    clear_screen(COLOR_BLACK);
    fill_rectangle(color_maroon(), 0,100,1600,150);
    draw_bitmap("game_over", 0, 100);

    // shows screen until quit is requested and refreshes screen
    while (not quit_requested())
    {
        process_events();
        refresh_screen(60);
    }
}
// check if player collides with wall, obstacle, teleporter or button
void check_obstacle_collision(game_data &game)
{
    // on level three when the player has 1 life left they can press space bar to become invincible
    if(game.current_level == 2 and game.player.lives == 1 and key_typed(SPACE_KEY))
    {
        game.player.invincibility = true;
    }

    // if player is not invincible and collides with obstacle they are sent to start of level and lose a life
    for(int i = 0; i < game.level[game.current_level].obstacle.size(); i++)
    {
        if((sprite_collision(game.player.player_sprite, game.level[game.current_level].obstacle[i].obstacle_sprite)) and game.player.invincibility == false)
        {
            sprite_set_x(game.player.player_sprite, 50);
            sprite_set_y(game.player.player_sprite, (screen_height() - sprite_height(game.player.player_sprite))/2);
            game.player.lives = game.player.lives - 1;
        }
    }
    // if player collides with wall and is not invincible they are sent to start of level and lose a life
    for(int i = 0; i < game.level[game.current_level].wall.size(); i++)
    {
        if(sprite_collision(game.player.player_sprite, game.level[game.current_level].wall[i].wall_sprite) and game.player.invincibility == false)
        {
            sprite_set_x(game.player.player_sprite, 50);
            sprite_set_y(game.player.player_sprite, (screen_height() - sprite_height(game.player.player_sprite))/2);
            game.player.lives = game.player.lives - 1;
        }
    }
    // if player collides with teleporter they gain a life and next level is loaded, if it is the final level the end screen is displayed
    if(sprite_collision(game.player.player_sprite, game.level[game.current_level].teleporter_sprite))
    {
        sprite_set_x(game.player.player_sprite, 50);
        sprite_set_y(game.player.player_sprite, (screen_height() - sprite_height(game.player.player_sprite))/2);
        game.player.lives = game.player.lives + 1;
        if(game.current_level == 2)
        {
            draw_end_screen();
        }
        else
        {
            game.current_level = game.current_level + 1;
        }
    }

    // when player collides with button the last obstacle in the vector which is predetermined to be blocking the way to teleporter is removed
    if((sprite_collision(game.player.player_sprite, game.level[game.current_level].button_sprite)) and  game.level[game.current_level].wall.size() > 14)
    {
        game.level[game.current_level].wall.pop_back();
    }
}
// checks if obstacles hit wall
void check_obstacle_wall_collision(game_data &game)
{
    // checks all obstacles for collision with all walls and reverses movement if they collide
    for(int i = 0; i < game.level[game.current_level].obstacle.size(); i++)
    {
        for(int j = 0; j < game.level[game.current_level].wall.size(); j++)
        {
            if(sprite_collision(game.level[game.current_level].wall[j].wall_sprite, game.level[game.current_level].obstacle[i].obstacle_sprite))
            {
                sprite_set_dx(game.level[game.current_level].obstacle[i].obstacle_sprite, -1 * sprite_dx(game.level[game.current_level].obstacle[i].obstacle_sprite));
            }
        }

    }
}
// draws all sprites to screen
void draw_game(game_data game)
{
    // makes window background black
    clear_screen(COLOR_BLACK);
    // draws all obstacles in current level to screen
    draw_obstacles(game.level[game.current_level]);
    // draws all walls in current level to screen
    draw_walls(game.level[game.current_level]);
    // draws player to screen
    draw_player(game.player);
    // draws messages/hints to player
    draw_message(game);
    // draws lives to top of screen
    draw_lives(game.player);
}
// updates all movement, checks for collision and draws sprites
void update_game(game_data &game)
{   
    // updates player and obstacle movement
    update_player(game.player);
    update_obstacles(game.level[game.current_level]);
    // draws all objects to game
    draw_game(game);
    draw_obstacles(game.level[game.current_level]);
    // checks for collision between objects
    check_obstacle_collision(game);
    check_obstacle_wall_collision(game);
    // refreshes screen
    refresh_screen(60);
}
// draws title screen
void draw_title_screen()
{
    // draws title sprite to screen with prompt saying press enter
    clear_screen(COLOR_BLACK);
    fill_rectangle(color_maroon(), 0,100,1600,150);
    draw_text("Press Enter", COLOR_WHITE, 765, 400);
    draw_bitmap("title", 0, 100);

    // when enter is pressed next menu is loaded
    while (not key_typed(RETURN_KEY))
    {
        process_events();
        refresh_screen(60);
    }
}
// draws menu allowing player to decide colour of player model
void draw_menu(player_data player)
{
    clear_screen(COLOR_BLACK);
    // draws menu requesting user to select colour and press space bar when they are complete to load first level
    while (not key_typed(SPACE_KEY))
    {
        process_events();
        fill_rectangle(color_maroon(), 0,100,1600,150);
        draw_text("1: Red  2:Blue  3: Green", COLOR_WHITE, 700, 300);
        draw_text("Press Space Bar To Begin", COLOR_WHITE, 700, 650);
        draw_bitmap("menu", 0, 100);

        // swaps player colour to red
        if (key_typed(NUM_1_KEY))
        {
            clear_screen(COLOR_BLACK);
            player_switch_colour(player, RED);
            draw_bitmap("red_player", 765, 400);
        }

        // swaps player colour to blue
        if (key_typed(NUM_2_KEY))
        {
            clear_screen(COLOR_BLACK);
            player_switch_colour(player, BLUE);
            draw_bitmap("blue_player", 765, 400);
        }

        // swaps player colour to green
        if (key_typed(NUM_3_KEY))
        {
            clear_screen(COLOR_BLACK);
            player_switch_colour(player, GREEN);
            draw_bitmap("green_player", 765, 400);
        }

        refresh_screen(60);
    }
    
}
// generates the levels with obstacles, teleporter, walls and button
level_data create_level(int level)
{
    level_data result;
    
    // sets level number, creates teleporter and button sprite
    result.level_number = level;
    result.teleporter_sprite = create_sprite("teleporter");
    result.button_sprite = create_sprite("button");

    // creates three levels with individual designs and obstacle/wall layouts
    switch (level)
    {
    case 1:
        for(int i = 0; i < 3; i++)
        {
            result.obstacle.push_back(create_obstacle_level_1(i));
        };
        draw_teleporter(result.teleporter_sprite);
    break;
    case 2:
        for(int i = 0; i < 4; i++)
        {
            result.obstacle.push_back(create_obstacle_level_2(i));
        };
        for(int i = 0; i < 15; i++)
        {
            result.wall.push_back(create_wall_level_2(i));
        }
        draw_teleporter(result.teleporter_sprite);
        draw_button(result.button_sprite);
    break;
    case 3:
        int index = 200;
         for(int i = 0; i < 20; i++)
         {
             result.obstacle.push_back(create_obstacle_level_3(i, index));
             index = index + 75;
         };
        draw_teleporter(result.teleporter_sprite);
    break;
    }

    return result;
}
// creates game with player and levels
game_data create_game()
{
    game_data result;
    
    // creates three levels and adds them to level vector
    for(int i = 0; i < 3; i++)
    {
        result.level.push_back(create_level(i+1));
    }

    // creates player and sets intial level to 0
    result.player = create_player();
    result.current_level = 0;

    return result;
}
// opens game window, loads resources, creates game and begins game showing title screen, menu and then levels allowing the player to play as well as exit.
int main()
{
    // opens window
    open_window("Must Escape", 1600, 800);
    // loads resource bundle
    load_resources();

    // creates new game with player and levels
    game_data game;
    game = create_game();

    // displays title screen and player colour selection menu after
    draw_title_screen();
    draw_menu(game.player);

    // draws and updates game using player input until exit is requested
    while ( not quit_requested())
    {
        process_events();

        handle_input(game.player);

        update_game(game);

        // when the players lives run out game ends
        if(game.player.lives == 0)
        {
            draw_end_screen();
        }
    }

    return 0;
}