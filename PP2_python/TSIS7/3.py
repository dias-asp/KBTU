import pygame

pygame.init()
screen = pygame.display.set_mode((500, 500))
done = False
clock = pygame.time.Clock()

x = 30
y = 30
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

    pressed = pygame.key.get_pressed()
    if pressed[pygame.K_UP]: y -= 20
    if pressed[pygame.K_DOWN]: y += 20
    if pressed[pygame.K_LEFT]: x -= 20
    if pressed[pygame.K_RIGHT]: x += 20
    if x < 25: x = 25
    if y < 25: y = 25
    if x > 475: x = 475
    if y > 475: y = 475
    
    screen.fill((0, 0, 0))
    pygame.draw.circle(screen, (255, 0, 0), (x, y), 25)

    pygame.display.flip()
    clock.tick(60)
