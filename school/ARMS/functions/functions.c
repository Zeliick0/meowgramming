void setLED(uint16_t led) {
	GPIOD->MODER &= ~(3UL << led * 2);
	GPIOD->MODER |= (1UL << led * 2);
}
 
void wait(uint16_t time) {
	uint16_t a,b;
	for (a = 0; a < time; a++) {
		for (b = 0; b < time; b++){
		}
	}
}
 
void turnOnLED(uint16_t led) {
	GPIOD->ODR |= (1 << led);
}
 
void turnOffLED(uint16_t led) {
	GPIOD->ODR &= ~(1 << led);
}
