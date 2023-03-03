#ifdef _COMBO_HPP_
#define _COMBO_HPP_

class Combo {
    private:
        float score;
    public:
        Combo(); // constructor
        ~Combo(); // destructor

        void setScore(float number); // Setter
        float getScore(); // Getter
        
        void highCard(); 
        void pair();
        void twoPair();
        void threeOfAKind();
        void straight();
        void flush();
        void fullHouse();
        void fourOfKind();
        void straightFlush();

        void checkCombo();
}

#endif