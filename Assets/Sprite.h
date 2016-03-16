#pragma once

struct Animated_Sprite_Template
{
    Sprite* frames;
    int n_frames;
    int frame_duration;
};
struct Animated_Sprite_Instance
{
    Animated_Sprite_Template* templat;
    int current_frame;
    int current_frame_exposure;
    float x,y;
};

class Sprite
{
public:
    void LoadSprite(Sprite* sprite,const char* file_name,
                    unsigned int width,unsigned int height,D3DCOLOR key);
    void FreeSprite(Sprite* sprite);

    void LoadAnimatedSprite(Animated_Sprite_Template* templat,
                            const char* base_name,int width, int height, D3DCOLOR key,
                            int n_frames, int frame_duration);
    void FreeAnimatedSprite(Animated_Sprite_Template* templat );
    void CreateSpriteInstance(Animated_Sprite_Template* templat,
                            Animated_Sprite_Instance* instance );
    void UpdateAnimation(Animated_Sprite_Instance* instance );
    void DrawSpriteInstance( Animated_Sprite_Instance* instance );
};
