#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


struct Lamp {
    int power_w; // power value in watts 
    int brightness_lm; // brighness value in lumens pew watt
    int flask_opaque; // flask opaque in percents 0-100%
    char* flask_cover; // matte or glossy  
    int radius_cm; // radius of flask
    int lenght_cm; // lenght from base to very end of lamp
    int color_temperature_k; // for example:  "6500" in k
    char* energy_consuming_class; // for example: A, AA, AAA, 
    char* base_color; // color, or hex value, "white"
    char* base; // e27 or e17, etc
    char* type; // LED or incandescent (розжарювання) or gas lamp
};

void enterLamp(struct Lamp *p) {
    printf(" <- Enter lamp power in watts:");
    scanf("%d",&p->power_w); // power value in watts 
    printf(" <- Enter lamp brightness in lumens:");
    scanf("%d",&p->brightness_lm); // brighness value in lumens pew watt
    printf(" <- Enter flask opaque in percents 0 - 100:");
    scanf("%d",&p->flask_opaque); // flask opaque in percents 0-100%
    printf(" <- Enter flask cover type:"); // matte or glossy  
    p->flask_cover = (char*)calloc(sizeof(char), 40);
    scanf("%s", p->flask_cover); // lenght from base to very end of lamp
    fflush(stdin);
    printf(" <- Enter lamp radius in cm:");
    scanf("%d",&p->radius_cm); // radius of flask
    printf(" <- Enter lamp lenght in cm:");
    scanf("%d",&p->lenght_cm); // lenght from base to very end of lamp 
    printf(" <- Enter lamp temperature in k:");
    scanf("%d",&p->color_temperature_k);  // for example:  "6500" in k
    printf(" <- Enter energy consuming class:");
    p->energy_consuming_class = (char*)calloc(sizeof(char), 40); 
    scanf("%s", p->energy_consuming_class);
    fflush(stdin);
    printf(" <- Enter lamp base color:");
    p-> base_color = (char*)calloc(sizeof(char), 40); 
    scanf("%s", p->base_color);
    fflush(stdin);
    printf(" <- Enter lamp base type:");
    p-> base = (char*)calloc(sizeof(char), 40);
    scanf("%s", p->base); // 
    fflush(stdin);
    printf(" Enter lamp type:");
    p-> type = (char*)calloc(sizeof(char), 40);
    scanf("%s", p->type);
    fflush(stdin);
}

void printLamp(struct Lamp *p) {
    printf("  _______________________\n");
    printf(" | -> lamp power in watts: %d \n", p->power_w);
    printf(" | -> lamp brightness in lumens: %d \n", p->brightness_lm);
    printf(" | -> flask opaque in percents 0 - 100: %d \n", p->flask_opaque);
    printf(" | -> flask cover type: %s \n", p->flask_cover);
    printf(" | -> lamp radius in cm: %d \n",p->radius_cm );
    printf(" | -> lamp lenght in cm: %d \n",  p->lenght_cm);
    printf(" | -> lamp temperature in k: %d \n", p->color_temperature_k);
    printf(" | -> energy consuming class: %s \n", p->energy_consuming_class);
    printf(" | -> lamp base color: %s \n", p->base_color);
    printf(" | -> lamp base type: %s \n", p->base);
    printf(" | -> lamp type: %s \n", p->type);
}


int main() {
    int box_capacity = 1;
    //struct Lamp *box_of_lamps = (struct Lamp*)malloc(sizeof(struct Lamp));
    struct Lamp box_of_static_lamps[1];
    enterLamp(&box_of_static_lamps[0]);
    printLamp(&box_of_static_lamps[0]);
    //enterLamp(&box_of_lamps[0]);
    //printLamp(&box_of_lamps[0]);

    return 0;
}

