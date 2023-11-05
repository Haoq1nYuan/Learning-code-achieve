class Timer
{
    public:
        Timer (int hour, int minute);
        void Increase ();
        int Hours () {return hours;}
        int Minutes () {return minutes;}
    private:
        int minutes, hours;
};