#include "GameplayScene.h"
#include "Logger.h"

void GameplayScene::load()
{
	m_movingPiece = std::make_unique<Pieces::MovingPiece>(Pieces::PieceType::T, m_board.getDefaultMovingPieceSpawnPoint(), &m_board);

	//m_board.fixMovingPiece(*m_movingPiece);

	//delete m_movingPiece;
	//m_movingPiece = nullptr;


}

void GameplayScene::update(float dt)
{
	constexpr float PIECE_MOVE_PERIOD = 1.0f / CONST::PIECE_MOVE_SPEED;
	constexpr float PIECE_FALL_PERIOD = 1.0f / CONST::PIECE_FALL_SPEED;
	constexpr float PIECE_FALL_PERIOD_FAST = 1.0f / CONST::PIECE_FALL_SPEED_FAST;
	
	
	rotatePieceWithInput();
	

	m_movePieceTimer += dt;
	if (m_movePieceTimer >= PIECE_MOVE_PERIOD)
	{
		m_movePieceTimer = 0.0f;
		movePieceWithInput();
	}


	float fallPeriod = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
		? PIECE_FALL_PERIOD_FAST
		: PIECE_FALL_PERIOD;

	m_fallPieceTimer += dt;
	if (m_fallPieceTimer >= fallPeriod)
	{
		m_fallPieceTimer = 0.0f;
		fallPiece();
	}
}

void GameplayScene::render(sf::RenderWindow& window)
{
	m_board.draw(window);

	if (m_movingPiece != nullptr)
	{
		m_movingPiece->getPiece().draw(window);
	}
}

void GameplayScene::unload()
{
}

void GameplayScene::movePieceWithInput()
{
	//move moving piece with input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		m_movingPiece->moveCoords({ -1, 0 });
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		m_movingPiece->moveCoords({ 1, 0 });
	}
}

void GameplayScene::rotatePieceWithInput()
{
	static bool wasKeyPressed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (!wasKeyPressed) 		
			m_movingPiece->rotate(true);
		wasKeyPressed = true;
	}
	else 
		wasKeyPressed = false;
}


void GameplayScene::fallPiece()
{
	static Pieces::PieceType pieceType = Pieces::PieceType::I;
	sf::Vector2i checkCoords = m_movingPiece->getCoords() + sf::Vector2i{ 0, 1 };
	if (!m_movingPiece->areCoordsInBounds(checkCoords) || m_board.isPieceColliding(*m_movingPiece, checkCoords))
	{
		m_board.fixMovingPiece(*m_movingPiece);
		m_movingPiece = std::make_unique<Pieces::MovingPiece>(pieceType, m_board.getDefaultMovingPieceSpawnPoint(), &m_board);

		pieceType = static_cast<Pieces::PieceType>((static_cast<int>(pieceType) + 1) % 8);

		return;
	}

	m_movingPiece->moveCoords({ 0, 1 });
}
