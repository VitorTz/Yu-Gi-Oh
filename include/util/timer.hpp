#ifndef YUGIOH_TIMER_HPP
#define YUGIOH_TIMER_HPP


namespace yu {

    class Timer {

        private:
            const int max_frame;
            int frame_count = 0;

        public:
            Timer(const int max_frame) : max_frame(max_frame) { }
            void update() { ++frame_count; }
            bool check() {
                const bool s = frame_count >= max_frame;
                if (s) frame_count = 0;
                return s;
            }

    };

}


#endif