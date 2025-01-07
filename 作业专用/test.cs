class SingleTon 
{
    private static SingleTon instanceClass = new SingleTon ();

    public static SingleTon getInstanceClass () 
    {
        return instanceClass;
    }
    
    private SingleTon () {}
}


