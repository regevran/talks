
class shape {
    public:
        // const shape is undrawable
        // because drawing the shape requies internal
        // changes to it
        bool drawable() const {return false;}
        
        // non const shape might be drawable
        // but we must ask the concrete type
        bool drawable()
        {
            return ok_to_be_drawn();
        }        
    private:
        virtual bool ok_to_be_drawn() const = 0;
};

class me : public shape {
    private:
        bool ok_to_be_drawn() const override 
        {            
            // only if I did my hair
            return haircut;
        }

    private:
        bool haircut = true;
};


void draw(shape& s)
    // always false, even if I did my hair!
    pre(s.drawable())
{    
}

int main()
{
    me m;
    draw(m);  
}
