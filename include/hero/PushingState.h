/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 * 
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_HERO_PUSHING_STATE_H
#define SOLARUS_HERO_PUSHING_STATE_H

#include "hero/State.h"

namespace solarus {

/**
 * \brief The state "Pushing" of the hero.
 */
class Hero::PushingState: public Hero::State {

  public:

    PushingState(Hero& hero);
    ~PushingState();

    void start(const State* previous_state);
    void stop(const State* next_state);
    void update();
    bool can_avoid_conveyor_belt() const;
    bool can_start_sword() const;
    bool is_moving_grabbed_entity() const;
    void notify_grabbed_entity_collision();
    void notify_movement_finished();
    void notify_obstacle_reached();
    void notify_position_changed();

    bool can_be_hurt(Enemy* attacker) const;
    bool can_pick_treasure(EquipmentItem& item) const;
    bool is_shallow_water_obstacle() const;
    bool is_deep_water_obstacle() const;
    bool is_hole_obstacle() const;
    bool is_lava_obstacle() const;
    bool is_prickle_obstacle() const;

  private:

    int pushing_direction4;            /**< Direction where the hero is looking (0 to 3). */
    Detector* pushed_entity;           /**< The entity the hero is pushing or NULL. */
    PathMovement* pushing_movement;    /**< The movement created by this state.
                                        * The movement of the hero is also this object,
                                        * unless a script decided to change it. */
    void stop_moving_pushed_entity();

};

}

#endif

