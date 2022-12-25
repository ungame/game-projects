#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
    private:
        static Engine* _instance;

    private:
        Engine();

    public:
        static Engine* Instance() { return _instance = _instance != nullptr ? _instance : new Engine(); }

    public:
        ~Engine();
        void Run();
};

#endif
