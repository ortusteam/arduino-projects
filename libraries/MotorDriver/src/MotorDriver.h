#ifndef _MotorDriver_h
#define _MotorDriver_h

#include <Arduino.h>

enum direction { FORWARD, STOP, BACKWARD };

class Motor {

private:
    uint8_t speedPin, direction1Pin, direction2Pin; // PINS
    uint8_t speed;                                  // in percents
    direction direction;
    bool running;

    void writeSpeed( uint8_t speed ) {
        analogWrite( speedPin, map( speed, 0, 255, 0, 100 ) );
    }

    void writeDirection( direction dir ) {
        switch( dir ) {
        case FORWARD: {
            digitalWrite( direction1Pin, 1 );
            digitalWrite( direction2Pin, 0 );
            break;
        }
        case STOP: {
            digitalWrite( direction1Pin, 0 );
            digitalWrite( direction2Pin, 0 );
            break;
        }
        case BACKWARD: {
            digitalWrite( direction1Pin, 0 );
            digitalWrite( direction2Pin, 1 );
            break;
        }
        }
    }

public:
    Motor( uint8_t pwm, uint8_t in1, uint8_t in2 )
        : speed( 0 ), direction( STOP ), running( false ) {
        speedPin = pwm;
        direction1Pin = in1;
        direction2Pin = in2;
    }

    void setPins( ) {
        pinMode( speedPin, OUTPUT );
        pinMode( direction1Pin, OUTPUT );
        pinMode( direction2Pin, OUTPUT );
    }

    direction getDirection( ) {
        return direction;
    }

    uint8_t getSpeed( ) {
        return speed;
    }

    bool getState( ) {
        return running;
    }

    void setDirection( direction newDirection ) {
        direction = newDirection;
        if( running )
            writeDirection( direction );
    }

    void setSpeed( uint8_t newSpeed ) {
        speed = newSpeed;
        if( running )
            writeSpeed( speed );
    }

    void run( ) {
        running = 1;
        writeSpeed( speed );
        writeDirection( direction );
    }

    void run( direction dir ) {
        setDirection( dir );
        run( );
    }

    void run( uint8_t ) {
        setSpeed( speed );
        run( );
    }

    void run( direction dir, uint8_t speed ) {
        setDirection( dir );
        setSpeed( speed );
        run( );
    }

    void stop( ) {
        running = 0;
        writeSpeed( 0 );
        writeDirection( STOP );
    }
}