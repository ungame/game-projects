#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
    private:
        SDL_Color _rgba;

    public:
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = SDL_ALPHA_TRANSPARENT)
        {
            _rgba = SDL_Color{r, g, b, a};
        }

        inline SDL_Color RGBA() { return _rgba; }
        inline void SetRed(Uint8 r) { _rgba.r = r; }
        inline void SetGreen(Uint8 g) { _rgba.g = g; }
        inline void SetBlue(Uint8 b) { _rgba.b = b; }
        inline void SetAlpha(Uint8 a) { _rgba.a = a; }

    public:
        static inline Color* White() { return new Color(255, 255, 255); }
        static inline Color* Black() { return new Color(0, 0, 0); }
        static inline Color* Grey() { return new Color(198, 198, 198); }
        static inline Color* Red() { return new Color(255, 0, 0); }
        static inline Color* Green() { return new Color(0, 255, 0); }
        static inline Color* Blue() { return new Color(0, 0, 0); }
};

#endif
