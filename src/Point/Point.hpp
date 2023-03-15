#ifndef POINT_HPP
#define POINT_HPP

class Point {
    private:
        long value;
    public:
        Point(); // default ctor, value = 64
        Point(int); // ctor

        // getter / setter (don't set value directly, use for resetting game point only)
        // use Add instead for adding value
        long getValue() const;
        void setValue(int);

        /* value modification from player skills */
        void Half();
        void Double();
        void Quadruple();
        void Quarter();

        void Add(int);
};

#endif