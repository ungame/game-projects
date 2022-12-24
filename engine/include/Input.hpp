#ifndef INPUT_HPP
#define INPUT_HPP

class Input
{
    private:
        static Input* _instance;

    private:
        Input() {}

    public:
        static Input* Instance() { return _instance = _instance != nullptr ? _instance : new Input(); } 

    public:
        bool Listen();
};

#endif
