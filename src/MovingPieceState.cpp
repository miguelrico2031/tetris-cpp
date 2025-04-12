#include "MovingPieceState.h"
#include "GameplayScene.h"
#include "Logger.h"
#include "ClearRowsState.h"

MovingPieceState::MovingPieceState(GameplayScene& scene)
	: GameplayState(scene)
{
	m_movingPiece = std::make_unique<Pieces::MovingPiece>(
		m_scene.getGenerator().getNextRandomPiece(),
		m_board.getDefaultMovingPieceSpawnPoint(),
		m_board);
	Logger::log("new moving piece!");
	auto& nextPiecePanel = m_scene.getNextPiecePanel();
	nextPiecePanel.updateNextPieces(m_scene.getGenerator().getNext3Pieces());

}


void MovingPieceState::update(float dt)
{
	static float baseFallPeriod = m_scene.getLevel().getFallPeriod();
	
	if (!m_hasHeld && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
	{
		Pieces::PieceType oldPieceType = m_movingPiece->getPiece().getPieceType();
		Pieces::PieceType pieceType = m_scene.getGenerator().holdPiece(oldPieceType);
		m_scene.getHoldPanel().setHeldPiece(oldPieceType);

		m_movingPiece = std::make_unique<Pieces::MovingPiece>(
			pieceType,
			m_board.getDefaultMovingPieceSpawnPoint(),
			m_board);
		m_hasHeld = true;
		auto& nextPiecePanel = m_scene.getNextPiecePanel();
		nextPiecePanel.updateNextPieces(m_scene.getGenerator().getNext3Pieces());

	}

	handleRotationInput();

	m_movePieceTimer += dt;
	if (m_movePieceTimer >= CONST::PIECE_MOVE_PERIOD)
	{
		m_movePieceTimer = 0.0f;
		handleMoveInput();
	}

	float fallPeriod = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
					   sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
		? baseFallPeriod * CONST::PIECE_FALL_PERIOD_FAST
		: baseFallPeriod * CONST::PIECE_FALL_PERIOD;

	m_fallPieceTimer += dt;
	if (m_fallPieceTimer >= fallPeriod)
	{
		m_fallPieceTimer = 0.0f;
		fallPiece();
	}
}

void MovingPieceState::render(sf::RenderWindow& window)
{
	m_movingPiece->getPiece().draw(window);
}




void MovingPieceState::handleMoveInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		movePieceSideways(false);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
			 sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		movePieceSideways(true);
	}
}

void MovingPieceState::handleRotationInput()
{
	static bool wasUpKeyPressed;
	static bool wasZKeyPressed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (!wasUpKeyPressed)
			rotatePiece(true);
		wasUpKeyPressed = true;
	}
	else
		wasUpKeyPressed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
	{
		if (!wasZKeyPressed)
			rotatePiece(false);
		wasZKeyPressed = true;
	}
	else
		wasZKeyPressed = false;
}

void MovingPieceState::movePieceSideways(bool right)
{
	const auto& rotatedPiece = m_movingPiece->getPiece().getRotatedPiece();
	sf::Vector2i newCoords = m_movingPiece->getCoords() + sf::Vector2i{ right ? 1 : -1, 0 };
	if (m_board.isPieceInBounds(rotatedPiece, newCoords) && !m_board.isPieceColliding(rotatedPiece, newCoords))
		m_movingPiece->setCoords(newCoords);
}

void MovingPieceState::rotatePiece(bool right)
{
	const auto& nextRP = m_movingPiece->getPiece().getNextRotatedPiece(right);
	sf::Vector2i coords = m_movingPiece->getCoords();
	if (m_board.isPieceInBounds(nextRP, coords) && !m_board.isPieceColliding(nextRP, coords))
		m_movingPiece->getPiece().rotate(right);
}


void MovingPieceState::fallPiece()
{
	static Pieces::PieceType pieceType = Pieces::PieceType::I;
	sf::Vector2i checkCoords = m_movingPiece->getCoords() + sf::Vector2i{ 0, 1 };
	const auto& rotatedPiece = m_movingPiece->getPiece().getRotatedPiece();

	if (!m_board.isPieceInBounds(rotatedPiece, checkCoords) ||
		m_board.isPieceColliding(m_movingPiece->getPiece().getRotatedPiece(), checkCoords))
	{
		m_board.fixPieceInMatrix(m_movingPiece->getPiece(), m_movingPiece->getCoords());
		if (m_board.anyFullRows())
		{
			//cambiar a estado de esperar
			m_scene.SetState<ClearRowsState>();
		}
		else
		{
			//new movingPieceState
			m_scene.SetState<MovingPieceState>();
		}
	}
	else
		m_movingPiece->setCoords(checkCoords);
}
