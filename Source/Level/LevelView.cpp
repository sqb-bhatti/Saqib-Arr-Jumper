//
// Created by Saqib Bhatti on 28/11/24.
//

#include "../../Header/Level/LevelView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Level {
    using namespace Global;
    using namespace UI::UIElement;
    using namespace Level;

    LevelView::LevelView(LevelController* controller) {
        game_window = nullptr;
        level_controller = controller;
        createImages();
    }

    LevelView::~LevelView() {
        deleteImages();
    }

    void LevelView::initialize() {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        calculateBoxDimensions();
        initializeImages();
    }

    void LevelView::update() {
        updateImages();
    }

    void LevelView::render() {
        drawLevel();
    }

    void LevelView::createImages() {
        background_image = new ImageView();
        box_image = new ImageView();
        target_overlay_image = new ImageView();
        letter_one_overlay_image = new ImageView();
        letter_two_overlay_image = new ImageView();
        letter_three_overlay_image = new ImageView();
        obstacle_one_overlay_image = new ImageView();
        obstacle_two_overlay_image = new ImageView();
    }

    void LevelView::initializeImages() {
        background_image->initialize(Config::array_jumper_bg_texture_path,
                                     game_window->getSize().x,
                                     game_window->getSize().y, sf::Vector2f(0, 0));

        background_image->setImageAlpha(background_alpha);

        box_image->initialize(Config::box_texture_path, box_dimensions.box_width,
                              box_dimensions.box_height,
                              sf::Vector2f(0, 0));

        target_overlay_image->initialize(Config::target_texture_path, box_dimensions.box_width,
                                         box_dimensions.box_height,
                                         sf::Vector2f(0, 0));

        letter_one_overlay_image->initialize(Config::letter_one_texture_path,
                                             box_dimensions.box_width,
                                         box_dimensions.box_height,
                                         sf::Vector2f(0, 0));

        letter_two_overlay_image->initialize(Config::letter_two_texture_path,
                                             box_dimensions.box_width,
                                             box_dimensions.box_height,
                                             sf::Vector2f(0, 0));

        letter_three_overlay_image->initialize(Config::letter_three_texture_path,
                                             box_dimensions.box_width,
                                             box_dimensions.box_height,
                                             sf::Vector2f(0, 0));

        obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path,
                                               box_dimensions.box_width,
                                               box_dimensions.box_height,
                                               sf::Vector2f(0, 0));

        obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path,
                                               box_dimensions.box_width,
                                               box_dimensions.box_height,
                                               sf::Vector2f(0, 0));

    }

    void LevelView::updateImages() {
        background_image->update();
        box_image->update();

        target_overlay_image->update();
        letter_one_overlay_image->update();
        letter_two_overlay_image->update();
        letter_three_overlay_image->update();
        obstacle_one_overlay_image->update();
        obstacle_two_overlay_image->update();

    }

    void LevelView::drawLevel() {
        background_image->render();

        for(int i = 0; i < LevelData::number_of_boxes; i++) {
            // Store the box's position
            sf::Vector2f position = calculateBoxPosition(i);

            // Store block's value
            BlockType blockTypeToDraw = level_controller->getCurrentBoxValue(i);

            drawBox(position);
            drawBoxValue(position, blockTypeToDraw);
        }
    }

    void LevelView::deleteImages() {
        delete(background_image);
        delete(box_image);

        delete(target_overlay_image);
        delete(letter_one_overlay_image);
        delete(letter_two_overlay_image);
        delete(letter_three_overlay_image);
        delete(obstacle_one_overlay_image);
        delete(obstacle_two_overlay_image);
    }

    void LevelView::calculateBoxDimensions() {
        //Return if there is no game window
        if(!game_window) {
            return;
        }

        calculateBoxWidthHeight();
        calculateBoxSpacing();
    }

    void LevelView::calculateBoxWidthHeight() {
        float screenWidth = static_cast<float>(game_window->getSize().x);
        int numBoxes = LevelData::number_of_boxes;

        //Each Box has a Gap on it's left, 1 extra gap for last block's right side
        int numGaps = numBoxes + 1;

        //Total space consumed by all gaps
        float totalSpaceByGaps = box_dimensions.box_spacing_percentage * static_cast<float>(numGaps);

        //Total space consumed by boxes and gaps
        float totalSpace = numBoxes + totalSpaceByGaps;

        box_dimensions.box_width = screenWidth / (totalSpace);
        box_dimensions.box_height = box_dimensions.box_width;
    }

    void LevelView::calculateBoxSpacing() {
        box_dimensions.box_spacing = box_dimensions.box_width * box_dimensions.box_spacing_percentage;
    }

    sf::Vector2f LevelView::calculateBoxPosition(int index) {
        float xPosition = box_dimensions.box_spacing + static_cast<float>(index) *
                (box_dimensions.box_width + box_dimensions.box_spacing);

        float yPosition = static_cast<float>(game_window->getSize().y) -
                box_dimensions.box_height - box_dimensions.bottom_offset;

        return sf::Vector2f(xPosition, yPosition);
    }

    UI::UIElement::ImageView* LevelView::getBoxOverlayImage(BlockType block_type) {
        switch (block_type) {
            case BlockType::OBSTACLE_ONE:
                return obstacle_one_overlay_image;
                break;
            case BlockType::OBSTACLE_TWO:
                return obstacle_two_overlay_image;
                break;
            case BlockType::ONE:
                return letter_one_overlay_image;
                break;
            case BlockType::TWO:
                return letter_two_overlay_image;
                break;
            case BlockType::THREE:
                return letter_three_overlay_image;
                break;
            case BlockType::TARGET:
                return target_overlay_image;
                break;
            default:
                return nullptr;
        }
    }

    void LevelView::drawBox(sf::Vector2f position) {
        box_image->setPosition(position);
        box_image->render();
    }

    void LevelView::drawBoxValue(sf::Vector2f position, BlockType box_value) {
        ImageView* image = getBoxOverlayImage(box_value);
        image->setPosition(position);
        image->render();
    }
}