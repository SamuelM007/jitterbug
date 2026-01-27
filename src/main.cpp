#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include <bn_vector.h>
#include <bn_keypad.h>

#include "bn_sprite_items_bug.h"


int main(){
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(15,15,0));

    bn::vector<bn::sprite_ptr, 50> beetles = {};

    // bn::sprite_ptr beetle = bn::sprite_items::bug.create_sprite();

    while(true){
        for(bn::sprite_ptr& beetle : beetles){
            bn::fixed new_x = beetle.x() + rng.get_fixed(-1,1);
            bn::fixed new_y = beetle.y() + rng.get_fixed(-1,1);
            
            beetle.set_x(new_x);
            beetle.set_y(new_y);
        }


        if(bn::keypad::a_pressed()){
            beetles.push_back(bn::sprite_items::bug.create_sprite());
        }

        rng.update();
        bn::core::update();
    }
}