class Game {

  private Team team1;
  private Team team2;

  public Game(Team team1, Team team2) {
    this.team1 = team1;
    this.team2 = team2;
  }

  public static void main(String[] args) {
    List<Player> lPlayers = //initializes lengaburu players
      List<Player> ePlayers = //initializes enchai players 
      Team lengaburu = new Team(lPlayers);
      Team enchai = new Team(ePlayers);

      Game game = new Game(lengaburu, enchai);
    game.play();
  }

  public void play() {
    Innings lengaburuBattingInnings = new Innings(team1,
      "batting");
    lengaburuBattingInnings.batting();
  }
}


class Innings {
  private Team team;

  Innings(Team team, String type) {
    this.team = team;
    this.type = type;
  }

  public void batting() {
    Batsman striker = team.getBatsmans(0);
    Batsman nonStriker = team.getBatsmans(1);
    for (int i = 0; i<overs; i++) {
      for (int j = 1; j<7; j++) {
        int runs = striker.bat();
        //update runs or wickets
        //update score
        //update commentary and all the rest of logic
      }
    }
  }
}


class Team {
  private ScoreCard teamScore;
  private List<Player> players;

  Team(List<Player> players) {
    this.players = players;
  }

  public void updateScore(int runs, int wickets) {
    this.scores.scoreRun(runs);
    this.scores.scoreWicket(wickets);
  }

  public getPlayer(int order) {
    return players.get(order);
  }
}

enum BatsmanState {
  bATTING, OUT, RETIRED, DNB
}


class Player {
  private String name;
  Player(String name) {
    this.name = name;
  }
}


class Batsman extends Player {
  private int[] probability;
  private ScoreCard scores;
  private BatsmanState state;


  Batsman(String name, int[] probability) {
    super(name);
    this.probability = probability;
  }


  public int bat() {
    int r = 0; //find the random runs 
    return r;
  }


  public void updateRuns(int runs) {
    this.scores.scoreRun(runs);
  }


  public void out() {
    this.state = OUT;
  }
}


class ScoreCard {
  int runsScored;
  int wicketsTaken;


  public void scoreRun(int runs) {
    this.runsScored = this.runsScored + runs;
  }
  public void scoreWicket(int runs) {
    this.runsScored = this.runsScored + runs;
  }
}
