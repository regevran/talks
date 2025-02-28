
class object
{
    public:
        object() {}
        object(const object& o)
         : movement_ratio(o.movement_ratio)
         {}

    public:
        // const objects are always reflectable, no movement
        bool reflectable() const {return true;}

        // non-const objects are reflectable based on a threshold
        bool reflectable() {
            // above this ratio the reflection
            // is not good enough so we spend a lot of
            // moeny making this reflection but
            // with poor and unusable results
            return movement_ratio < 11.3;
        }

    public:
       float movement_ratio = 0.0;
};

object slowdown(const object& o)
    post (ret: ret.reflectable())
{
    object ret(o);

    // bug (using old ratio)
    ret.movement_ratio = 12.4;

    return ret;
}

int main()
{
    object o;
    o.movement_ratio = 14.7;
    auto slowed = slowdown(o);

    // here we spend a lot of moeny
    // because of constification
}
