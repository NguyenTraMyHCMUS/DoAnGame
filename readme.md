```mermaid
classDiagram
    %% Core Components
    class Game {
        -sf::RenderWindow _window
        -ResourceManager _resourceManager
        -GameTimer _gameTimer
        -Field _field
        -NextTetrominoPreview _nextPreview
        -ScoreManager _scoreManager
        -LevelManager _levelManager
        -unique_ptr~IGameRenderer~ _renderer
        -unique_ptr~IInputHandler~ _inputHandler
        -unique_ptr~Tetromino~ _tetromino
        -unique_ptr~IGameStateManager~ _stateManager
        -unique_ptr~IGameLogic~ _gameLogic
        -float _delay
        -string _playerName
        +Game()
        +update()
        +resetGame()
        +getWindow()
        +getResourceManager()
        +getRenderer()
        +getInputHandler()
        +getGameTimer()
        +getField()
        +getTetromino()
        +getNextTetrominoPreview()
        +getScoreManager()
        +getLevelManager()
        +getStateManager()
        +getGameLogic()
        +setDelay()
        +getDelay()
        +getPlayerName()
        +setPlayerName()
    }

    class GameLoop {
        -Game& _game
        +GameLoop(Game&)
        +run()
    }

    %% States
    class GameState {
        <<interface>>
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    class IGameStateManager {
        <<interface>>
        +setState(unique_ptr~GameState~)
        +getStatePtr()
    }

    class GameStateManager {
        -unique_ptr~GameState~ _currentState
        +setState(unique_ptr~GameState~)
        +getStatePtr()
    }

    class MainMenuState {
        -Game& _game
        -sf::Texture _menuBackgroundTexture
        -sf::Sprite _menuBackgroundSprite
        -sf::Font _fontTitle
        -sf::Font _fontWelcome
        -sf::Text _welcome
        -sf::Font _font
        -sf::Text _title
        -sf::Texture _buttonTexture
        -sf::Sprite _buttonSprites[3]
        -sf::Text _menuOptions[3]
        -int _selectedIndex
        +MainMenuState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    class PlayingState {
        -Game& _game
        -sf::Font _font
        +PlayingState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }
    
    class PausedState {
        -Game& _game
        -sf::Texture _pausedTexture
        -sf::Sprite _pausedSprite
        -sf::Font _font
        -sf::Text _title
        -sf::Text _menuOptions[2]
        -int _selectedIndex
        +PausedState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    class GameOverState {
        -Game& _game
        -sf::Texture _gameOverTexture
        -sf::Sprite _gameOverSprite
        -sf::Font _font
        -sf::Text _title
        -sf::Text _menuOptions[2]
        -sf::Text _topScoreTexts[3]
        -int _selectedIndex
        +GameOverState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    class PlayerNameState {
        -std::string _playerName
        -sf::Font _font
        -sf::Text _titleText
        -sf::Text _promptText
        -sf::Text _inputText
        -sf::RectangleShape _inputBox
        -sf::Text _guideText
        -bool _nameEntered
        -float _cursorTimer
        -bool _showCursor
        +PlayerNameState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    class InstructionsState {
        -Game& _game
        -sf::Texture _instructionTexture
        -sf::Sprite _instructionSprite
        -sf::Font _font
        -sf::Text _title
        -sf::Text _instructions
        -sf::Text _backOption
        +InstructionsState(Game&)
        +handleInput(Game&)
        +draw(Game&)
        +update(Game&)
    }

    %% Game Logic
    class IGameLogic {
        <<interface>>
        +update(int dx, bool rotate)
        +moveTetrominoHorizontally(int dx)
        +rotateTetrominoIfPossible(bool rotate)
        +moveTetrominoDown()
        +isGameOver()
        +handleLineClearing()
        +resetGame()
        +renderEffect(sf::RenderWindow&)
    }

    class GameLogic {
        -Field& _field
        -unique_ptr~Tetromino~& _tetromino
        -NextTetrominoPreview& _nextPreview
        -ScoreManager& _scoreManager
        -LevelManager& _levelManager
        -float& _delay
        -unique_ptr~ILineEffect~ _lineEffect
        -vector~int~ _linesToClear
        -bool _effectActive
        +GameLogic(Field&, unique_ptr~Tetromino~&, NextTetrominoPreview&, ScoreManager&, LevelManager&, float&)
        +update(int dx, bool rotate)
        +moveTetrominoHorizontally(int dx)
        +rotateTetrominoIfPossible(bool rotate)
        +moveTetrominoDown()
        +isGameOver()
        +handleLineClearing()
        +resetGame()
        +renderEffect(sf::RenderWindow&)
    }

    class Field {
        -int _height
        -int _width
        -vector~vector~int~~ _field
        +Field(int width, int height)
        +isLineComplete(int y)
        +removeLines(vector~int~)
        +getCompletedLines()
        +isPositionValid(int x, int y)
        +isGameOver()
        +reset()
        +lock(Tetromino*)
        +getField()
        +getHeight()
        +getWidth()
    }

    %% Score & Level
    class ScoreManager {
        -int _currentScore
        -int _highScore
        -string _highScoreFile
        -vector~pair~string, int~~ _topScores
        -void loadHighScore()
        -void saveHighScore()
        +ScoreManager()
        +~ScoreManager()
        +addScore(int points)
        +getScore()
        +getHighScore()
        +reset()
        +submitScore(string)
        +getTopScores(int n)
    }

    class LevelManager {
        -int _currentLevel
        -int _linesCleared
        +LevelManager()
        +increaseLevel()
        +addClearedLines(int)
        +getLevel()
        +getLinesCleared()
        +reset()
        +resetLinesCleared()
    }

    %% Input
    class IInputHandler {
        <<interface>>
        +handleInput(Game&)
        +getDx()
        +getRotate()
        +reset()
    }

    class InputManager {
        -int _dx
        -bool _rotate
        +InputManager()
        +handleInput(Game&)
        +getDx()
        +getRotate()
        +reset()
    }
    
    class PlayerNameInput {
        -sf::RenderWindow& _window
        -std::string _playerName
        -sf::Font _font
        -sf::Text _promptText
        -sf::Text _inputText
        +PlayerNameInput(sf::RenderWindow&)
        +std::string getPlayerName()
    }

    %% Graphics
    class IGameRenderer {
        <<interface>>
        +clear()
        +display()
        +drawBackground()
        +drawField(Field&)
        +drawTetromino(Tetromino*)
        +drawInfoBox(string, string, float)
        +drawNextPreview(NextTetrominoPreview&)
        +drawStats(ScoreManager&, LevelManager&)
        +drawFrame()
    }

    class GameRenderer {
        -sf::RenderWindow& _window
        -ResourceManager& _resources
        +GameRenderer(sf::RenderWindow&, ResourceManager&)
        +clear()
        +display()
        +drawBackground()
        +drawField(Field&)
        +drawTetromino(Tetromino*)
        +drawInfoBox(string, string, float)
        +drawNextPreview(NextTetrominoPreview&)
        +drawStats(ScoreManager&, LevelManager&)
        +drawFrame()
    }

    class ResourceManager {
        -sf::Texture _tileTexture
        -sf::Texture _backgroundTexture
        -sf::Font _font
        +loadResources()
        +getTileTexture()
        +getBackgroundTexture()
        +getFont()
    }

    class ILineEffect {
        <<interface>>
        +update(float deltaTime)
        +startEffect(vector~int~)
        +isActive()
        +draw(sf::RenderWindow&)
    }
    
    class FlashLineEffect {
        -vector<int> _linesToClear
        -float _timer
        -float _duration
        -bool _active
        -int _flashCount
        -sf::Color _currentColor
        -int _cellSize
        -int _gridOffsetX
        -int _gridOffsetY
        -int _numColumns
        +FlashLineEffect(int cellSize, int gridOffsetX, int gridOffsetY, int numColumns, float duration)
        +startEffect(const vector<int>& lines)
        +update(float deltaTime) bool
        +draw(sf::RenderWindow& window)
        +isActive() const bool
    }

    %% Tetromino
    class Tetromino {
        <<abstract>>
        #vector~Point~ _blocks
        #vector~Point~ _backupBlocks
        #int _color
        #unique_ptr~ITetrominoValidator~ _validator
        #unique_ptr~ITetrominoMovement~ _movement
        #unique_ptr~ITetrominoRotator~ _rotator
        #unique_ptr~ITetrominoRenderer~ _renderer
        #unique_ptr~ITetrominoState~ _state
        #unique_ptr~ITetrominoLocker~ _locker
        +Tetromino()
        +draw(sf::RenderWindow&, sf::Sprite&)
        +move(int dx)
        +fall()
        +rotate()
        +lockToField(Field&)
        +isValid(Field&)
        +clone()
        +backupState()
        +restoreState()
    }

    class ITetromino {
        +ITetromino()
        -void initializeShape()
        +clone()
    }

    class JTetromino {
        +JTetromino()
        -void initializeShape()
        +clone()
    }

    class LTetromino {
        +LTetromino()
        -void initializeShape()
        +clone()
    }

    class OTetromino {
        +OTetromino()
        -void initializeShape()
        +clone()
    }
    
    class STetromino {
        +STetromino()
        -void initializeShape()
        +clone()
    }
    
    class ZTetromino {
        +ZTetromino()
        -void initializeShape()
        +clone()
    }

    class TTetromino {
        +TTetromino()
        -void initializeShape()
        +clone()
    }

    %% Time
    class GameTimer {
        -sf::Clock clock
        -float timer
        -float delay
        +GameTimer(float initialDelay)
        +update()
        +shouldUpdate()
        +restart()
        +setDelay(float)
        +getDelay()
        +getTimer()
    }

    %% Preview
    class NextTetrominoPreview {
        -unique_ptr~Tetromino~ _nextTetromino
        +NextTetrominoPreview()
        +generateNext()
        +getNext()
        +cloneNext()
    }

    %% Component interfaces
    class ITetrominoValidator {
        <<interface>>
        +isValid(vector~Point~&, Field&)
    }
    
    class ITetrominoMovement {
        <<interface>>
        +move(int dx)
        +fall()
    }
    
    class ITetrominoRotator {
        <<interface>>
        +rotate(vector~Point~&)
    }
    
    class ITetrominoRenderer {
        <<interface>>
        +draw(sf::RenderWindow&, sf::Sprite&, int color)
        +setCellSize(int)
        +getCellSize()
    }
    
    class ITetrominoState {
        <<interface>>
        +backup(vector~Point~&)
        +restore(vector~Point~&)
    }
    
    class ITetrominoLocker {
        <<interface>>
        +lock(Field& field)
    }
    
    class IRotator {
        <<interface>>
        +rotate(vector~Point~&)
    }
    
    class IRenderingStrategy {
        <<interface>>
        +render(sf::RenderWindow&, sf::Sprite&, Point, int cellSize, int color)
    }

    %% Point class
    class Point {
        +int x
        +int y
        +Point(int x, int y)
    }

    %% Component implementations
    class TetrominoValidator {
        +isValid(vector~Point~&, Field&)
    }

    class TetrominoMovement {
        -vector~Point~& _blocks
        +TetrominoMovement(vector~Point~&)
        +move(int dx)
        +fall()
    }

    class StandardRotator {
        +rotate(vector~Point~&)
    }
    
    class CounterclockwiseRotator {
        +rotate(vector~Point~&)
    }

    class TetrominoRenderer {
        -vector~Point~& _blocks
        -int _cellSize
        -IRenderingStrategy* _strategy
        +draw(sf::RenderWindow&, sf::Sprite&, int color)
        +setCellSize(int)
        +getCellSize()
    }

    class TetrominoState {
        -vector~Point~ _backupBlocks
        +backup(vector~Point~&)
        +restore(vector~Point~&)
    }
    
    class TetrominoLocker {
        -vector~Point~& _blocks
        +TetrominoLocker(vector~Point~&)
        +lock(Field& field)
    }
    
    class GameFieldRenderingStrategy {
        +render(sf::RenderWindow&, sf::Sprite&, Point, int cellSize, int color)
    }
    
    class PreviewRenderingStrategy {
        +render(sf::RenderWindow&, sf::Sprite&, Point, int cellSize, int color)
    }
    
    %% Configuration
    class ConfigurationManager {
        -static ConfigurationManager _instance
        -std::map<std::string, std::string> _config
        +static ConfigurationManager& getInstance()
        +bool loadFromFile(string path)
        +setInt(string key, int value)
        +getInt(string key)
        +setString(string key, string value)
        +getString(string key)
    }
    
    class ColorMapper {
        -static ColorMapper _instance
        -std::map<int, sf::Color> _colorMap
        +static ColorMapper& getInstance()
        +sf::Color getColor(int index)
        +void updateFromConfig()
    }
    
    class IColorMapper {
        <<interface>>
        +getColor(int index)
    }
    
    %% Events
    class ITetrominoEventListener {
        <<interface>>
        +onLineCleared(int)
        +onTetrominoLocked()
    }
    
    class TetrominoEventManager {
        -vector<ITetrominoEventListener*> _listeners
        +addListener(ITetrominoEventListener*)
        +removeListener(ITetrominoEventListener*)
        +notifyLineCleared(int)
        +notifyTetrominoLocked()
    }
    
    %% Factories
    class TetrominoFactory {
        +static unique_ptr<Tetromino> createTetromino(int type)
        +static unique_ptr<Tetromino> createRandomTetromino()
    }
    
    class ITetrominoComponentFactory {
        <<interface>>
        +createState()
        +createMovement()
        +createRotator()
        +createValidator()
        +createRenderer()
        +createLocker()
    }
    
    class DefaultTetrominoComponentFactory {
        +createState()
        +createMovement()
        +createRotator()
        +createValidator()
        +createRenderer()
        +createLocker()
    }
    
    class RotatorFactory {
        +createRotator(string type)
    }
    
    %% Registries
    class TetrominoTypeRegistry {
        -static map<string, TetrominoTypeInfo> _registry
        +registerType(TetrominoTypeInfo)
        +getTypeInfo(string)
    }
    
    class TetrominoTypeInfo {
        -string _name
        -int _color
        +TetrominoTypeInfo(string name, int color)
        +string getName()
        +int getColor()
    }
    
    class TetrominoFactoryRegistry {
        -static map<string, function> _registry
        +registerFactory(string, function)
        +createTetromino(string)
    }
    
    class TetrominoAutoRegistrar {
        +TetrominoAutoRegistrar(string, function)
    }
    
    class RotatorFactoryRegistry {
        -static map<string, function> _registry
        +registerFactory(string, function)
        +createRotator(string)
    }
    
    class RotatorFactoryInitializer {
        +static void initialize()
    }
    
    %% Relationships
    %% Game Relationships
    Game *-- Field : contains
    Game *-- NextTetrominoPreview : contains
    Game *-- ScoreManager : contains
    Game *-- LevelManager : contains
    Game *-- GameTimer : contains
    Game *-- ResourceManager : contains
    Game o-- "1" Tetromino : has
    Game *-- IGameStateManager : contains
    Game *-- IGameLogic : contains
    Game *-- IGameRenderer : contains
    Game *-- IInputHandler : contains
    
    GameLoop o-- Game : references

    %% State Management
    IGameStateManager <|.. GameStateManager : implements
    GameStateManager o-- GameState : manages
    GameState <|.. MainMenuState : implements
    GameState <|.. PlayingState : implements
    GameState <|.. PausedState : implements
    GameState <|.. GameOverState : implements
    GameState <|.. PlayerNameState : implements
    GameState <|.. InstructionsState : implements
    
    %% Core Logic Implementation
    IGameLogic <|.. GameLogic : implements
    IGameRenderer <|.. GameRenderer : implements
    IInputHandler <|.. InputManager : implements
    GameLogic o-- ILineEffect : uses
    
   %% Tetromino Type Hierarchy
    Tetromino <|-- ITetromino : extends
    Tetromino <|-- JTetromino : extends
    Tetromino <|-- LTetromino : extends
    Tetromino <|-- OTetromino : extends
    Tetromino <|-- STetromino : extends
    Tetromino <|-- ZTetromino : extends
    Tetromino <|-- TTetromino : extends
    
    %% Tetromino Composition
    Tetromino *-- "4" Point : contains
    Tetromino o-- ITetrominoValidator : uses
    Tetromino o-- ITetrominoMovement : uses
    Tetromino o-- ITetrominoRotator : uses
    Tetromino o-- ITetrominoRenderer : uses
    Tetromino o-- ITetrominoState : uses
    Tetromino o-- ITetrominoLocker : uses

    %% Component Implementations
    ITetrominoValidator <|.. TetrominoValidator : implements
    ITetrominoMovement <|.. TetrominoMovement : implements
    ITetrominoState <|.. TetrominoState : implements
    ITetrominoLocker <|.. TetrominoLocker : implements
    ITetrominoRenderer <|.. TetrominoRenderer : implements
    
    %% Rotator System
    ITetrominoRotator <|.. IRotator : implements
    IRotator <|.. StandardRotator : implements
    IRotator <|.. CounterclockwiseRotator : implements
    
    %% Rendering Strategy Pattern
    TetrominoRenderer o-- IRenderingStrategy : uses
    IRenderingStrategy <|.. GameFieldRenderingStrategy : implements
    IRenderingStrategy <|.. PreviewRenderingStrategy : implements
    
    %% Component Dependencies
    TetrominoValidator --> Field : validates against
    TetrominoMovement --> Point : modifies
    TetrominoRenderer --> Point : renders
    TetrominoLocker --> Field : locks to
    
    %% Factory System
    TetrominoFactory ..> TetrominoFactoryRegistry : uses
    TetrominoFactory ..> TetrominoTypeRegistry : uses
    TetrominoFactory ..> ITetrominoComponentFactory : uses
    ITetrominoComponentFactory <|.. DefaultTetrominoComponentFactory : implements
    
    RotatorFactory ..> RotatorFactoryRegistry : uses
    RotatorFactory ..> IRotator : creates
    RotatorFactoryRegistry ..> StandardRotator : creates
    RotatorFactoryRegistry ..> CounterclockwiseRotator : creates
    
    %% Registry System
    TetrominoFactoryRegistry o-- TetrominoAutoRegistrar : registered by
    RotatorFactoryRegistry o-- RotatorFactoryInitializer : initialized by
    
    %% Event System
    TetrominoEventManager o-- ITetrominoEventListener : notifies
    
    %% Field and Preview
    Field *-- "M×N" int : grid contains
    NextTetrominoPreview o-- Tetromino : contains next
    
    %% Configuration
    DefaultTetrominoComponentFactory ..> RotatorFactory : uses
    DefaultTetrominoComponentFactory ..> ConfigurationManager : configures from
    ColorMapper ..> ConfigurationManager : reads config
    
    %% Player Name Input
    PlayerNameState --> PlayerNameInput : uses
    

    ```
