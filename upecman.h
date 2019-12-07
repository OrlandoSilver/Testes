typedef enum e_ghostmode {chase, scatter, afraid, dead} t_ghostmode;
typedef enum e_direction {up, left, down, right} t_direction;
typedef enum e_ghosts {blinky, pinky, inky, clyde} t_ghosts;

typedef struct st_position
{
    int y; /* line */
    int x; /* column */
} t_pos;

typedef struct st_pacman
{
    t_pos pos; /* current pacman position */
    t_direction dir; /* direction */
    t_pos anteripos;
    int life; /* how many lifes pacman has */
    int score; /* dot = 10 point; pill = 50 points; ghost = 750 points; cherry = 500 */
    int cereja;
    int primeira_pallet;

} t_pacman;

typedef struct st_ghost
{
    t_pos pos; /* ghost position */
    t_direction dir; /* ghost current direction */
    t_pos starget; /* ghost scatter preferred corner */
    t_pos target; /* ghost target */
    t_pos anteriorpos; /*ghost last position*/
    t_ghostmode mode; /* chase, scatter, afraid or dead */
    char iten_anterior;
    time_t inittime;
    time_t endtime;
    time_t time;
} t_ghost;

typedef struct st_pacdata
{
    char lab[LABL][LABC]; /* the labyrinth map */
    t_pacman pacman; /* pacman data */
    t_ghost ghost[4]; /* ghost[blinky], ghost[pinky], ghost[inky], ghost[clyde] */
} t_game;


/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
t_game upecman_init(void); /* initialize game variables */
void printlab(t_game g); /* print the labyrinth */
int end_game(t_game g);
t_game modeafraid(t_game g, int fant);
t_game mov_pac(t_game g, int kin);
t_game pontos(t_game g);    
t_game criacereja(t_game g);
/*t_game ghostmove(t_game g);*/
t_game fanmovi(t_game g);
/* Inky funcoes */
t_game inkychase(t_game g);
t_pos intermed(t_game g);
t_game alvoinky(t_pos intermed, t_game g);  
/* Pinky funcoes  */
t_game pinkychase(t_game g);
t_game pinkychase(t_game g);
/* Clyde funcoes*/
t_game clydechase(t_game g);
/* Modo dos fantasmas */
t_game changemode(t_game g, int fant);
double calculatempo(t_game g, int fant);
/* Movimento do ghost */
t_game mapa(t_game g, int nomeDoFantasma);
t_game ghostmove(t_game g);
t_game oneghost(t_game g, int fant);
t_game ghostm(t_game g, int fant);
t_game movernadirecao(t_game g, int nomeDoFantasma);
t_game colisao(t_game g);/*caso de colisao fantasma pacman*/
