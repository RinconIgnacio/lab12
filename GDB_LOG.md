
# GDB log

## Week 12 (Lab 12) - November 7, 2026

### Constructor Chain

Commands used:

    break Hangman::Hangman
    run
    bt
    step
    bt
    break Game::Game
    continue
    bt
    finish
    bt

Output:

    #0 Hangman::Hangman (this=0x7fffffffe1a0)
       at src/hangman_game.cpp:4
    #1 main () at app/main.cpp:50

    #0 Game::Game (this=0x7fffffffe1a0, title="Hangman")
       at src/game.cpp:8
    #1 Hangman::Hangman (this=0x7fffffffe1a0)
       at src/hangman_game.cpp:4
    #2 main () at app/main.cpp:50

    #0 Hangman::Hangman (this=0x7fffffffe1a0)
       at src/hangman_game.cpp:4
    #1 main () at app/main.cpp:50

I first tried using step, but it took me into the string allocator. After setting a breakpoint in Game, I could see that the base constructor was called from Hangman. Using finish brought me back to Hangman, which helped me understand the order.

### Destructor Chain

Commands used:

    break Hangman::~Hangman
    break Game::~Game
    continue
    bt
    continue
    bt
    continue
    bt

Output:

    #0 Game::~Game (this=0x7fffffffe1d0)
       at src/game.cpp:10
    #1 Minesweeper::~Minesweeper (this=0x7fffffffe1d0)
       at include/minesweeper_game.h:6
    #2 main () at app/main.cpp:87

    #0 Hangman::~Hangman (this=0x7fffffffe1a0)
       at include/hangman_game.h:6
    #1 main () at app/main.cpp:87

    #0 Game::~Game (this=0x7fffffffe1a0)
       at src/game.cpp:10
    #1 Hangman::~Hangman (this=0x7fffffffe1a0)
       at include/hangman_game.h:6
    #2 main () at app/main.cpp:87

Minesweeper was destroyed first because it was created last. I also noticed that Hangman's destructor ran before Game's destructor. So construction starts with the base class, while destruction happens in the opposite order.

### Inspecting Inheritance (Task 8)

I added `Game *g = &hangman;` in main and used GDB to compare the object and the pointer.

Commands:

    break app/main.cpp:54
    run
    print hangman
    print *g
    ptype Hangman
    ptype g
    whatis g

Output:

    (gdb) print hangman
    $1 = {<Game> = {m_title = "Hangman", m_last_score = 0},
      m_times_played = 0}

    (gdb) print *g
    $2 = {m_title = "Hangman", m_last_score = 0}

    (gdb) ptype Hangman
    type = class Hangman : public Game {
        int m_times_played;
      public:
        Hangman(void);
        void play(void);
        int times_played(void) const;
    }

    (gdb) ptype g
    type = class Game {
        std::string m_title;
        int m_last_score;
      public:
        Game(std::string);
        ~Game(void);
        const std::string & title(void) const;
        int last_score(void) const;
        void play(void);
      protected:
        void set_score(int);
        bool ask_play_again(void) const;
    } *

    (gdb) whatis g
    type = Game *

I noticed that printing Hangman showed both its own variable and the ones inherited from Game. But printing through g only showed the Game part. This helped me see how the type of a pointer affects what GDB displays.

