-- Mini Mowatulla: a small spider that comes from an egg.
-- This enemy is usually be generated by a bigger one.

in_shelter = nil

-- The enemy appears: create its movement
function event_appear()
  
  sol.enemy.set_life(2)
  sol.enemy.set_damage(2)
  sol.enemy.create_sprite("enemies/mini_mowatulla")
  sol.enemy.set_size(16, 16)
  sol.enemy.set_origin(8, 13)
  sol.enemy.set_invincible()

  sprite = sol.enemy.get_sprite()
  sol.main.sprite_set_animation(sprite, "shell")
  in_shell = true
  sol.main.timer_start(1000, "break_shell", false)

  m = sol.main.target_movement_create(64)
  sol.enemy.start_movement(m)
end

-- The enemy was stopped for some reason and should restart
function event_restart()

  if in_shell then
    sprite = sol.enemy.get_sprite()
    sol.main.sprite_set_animation(sprite, "shell")
  end
end

-- Starts breaking the shell
function break_shell()

  sprite = sol.enemy.get_sprite()
  sol.enemy.stop_movement()
  sol.main.sprite_set_animation(sprite, "shell_breaking")
end

--  The animation of a sprite is finished
function event_sprite_animation_finished(sprite, animation)

  -- if the shell was breaking, let the mini mowatulla go
  if animation == "shell_breaking" then
    sol.main.sprite_set_animation(sprite, "walking")
    sol.enemy.snap_to_grid()
    m = sol.main.path_finding_movement_create(64)
    sol.enemy.start_movement(m)
    sol.enemy.set_default_attack_consequences()
    in_shell = false
  end
end
