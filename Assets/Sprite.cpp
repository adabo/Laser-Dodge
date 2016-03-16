#include "Sprite.h"

void Sprite::LoadSprite( Sprite* sprite,const char* file_name,
        unsigned int width,unsigned int height,D3DCOLOR key)
{
    sprite->surface = (D3DCOLOR*)malloc( sizeof( D3DCOLOR ) * width * height );
    LoadBmp( file_name,sprite->surface );
    sprite->height = height;
    sprite->width = width;
    sprite->key = key;
}

void Sprite::FreeSprite(Sprite* sprite)
{
    free( sprite->surface );
}

void Sprite::LoadAnimatedSprite( Animated_Sprite_Template* templat, 
            const char* base_name,int width, int height, D3DCOLOR key, int n_frames, int frame_duration)
{
    templat->frames = (Sprite*)malloc( sizeof( Sprite ) * n_frames );

    for( int index = 0; index < n_frames; index++ )
    {
        char file_name_buffer[ 64 ];
        sprintf( file_name_buffer,"%s%.2d.bmp",base_name,index );
        LoadSprite( &templat->frames[ index ],file_name_buffer,width,height,key );
    }
    templat->n_frames = n_frames;
    templat->frame_duration = frame_duration;
}

void Sprite::FreeAnimatedSprite( Animated_Sprite_Template* templat )
{
    for( int index = 0; index < templat->n_frames; index++ )
    {
        FreeSprite( &templat->frames[ index ] );
    }

    free( templat->frames );
}

void Sprite::CreateSpriteInstance( Animated_Sprite_Template* templat,Animated_Sprite_Instance* instance )
{
    instance->templat = templat;
    instance->current_frame_exposure = 0;
    instance->current_frame = 0;
    instance->x = 0.0f;
    instance->y = 0.0f;
}

void Sprite::UpdateAnimation( Animated_Sprite_Instance* instance )
{
    instance->current_frame_exposure++;
    if( instance->current_frame_exposure >= instance->templat->frame_duration )
    {
        instance->current_frame++;  
        instance->current_frame %= instance->templat->n_frames;
        instance->current_frame_exposure = 0;  
    }
}
void Sprite::DrawSpriteInstance( Animated_Sprite_Instance* instance )
{
    gfx.DrawSprite( (int)instance->x,(int)instance->y,
            &instance->templat->frames[ instance->current_frame ] );
}