TTF_Font* font = TTF_OpenFont("font.ttf", 24);
if (!font) {
    printf("Failed to load font: %s\n", TTF_GetError());
    exit(1);
}

SDL_Color color = { 255, 255, 255 }; // white color
SDL_Surface* text_surface = TTF_RenderText_Solid(font, "Hello, World!", color);
if (!text_surface) {
    printf("Failed to render text: %s\n", TTF_GetError());
    exit(1);
}
