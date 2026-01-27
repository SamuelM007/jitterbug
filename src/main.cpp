#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_random.h>
#include "bn_sprite_items_bug.h"

int main(){
    bn::core::init();

    bn::random rng = bn::random();

    bn::backdrop::set_color(bn::color(15,15,0));

    bn::sprite_ptr beetle = bn::sprite_items::bug.create_sprite();

    while(true){
        bn::fixed new_x = beetle.x() + rng.get_fixed(-1,1);
        bn::fixed new_y = beetle.y() + rng.get_fixed(-1,1);

        beetle.set_x(new_x);
        beetle.set_y(new_y);



        bn::core::update();
    }
}