/*
** EPITECH PROJECT, 2025
** rtype
** File description:
** Pipe
*/

#ifndef PIPE_HPP_
    #define PIPE_HPP_

class Pipe {
    public:
        enum Type {
            TOP,
            BOTTOM
        };
        Pipe(Type type);
        Type getType() const;
    private:
        Type _type;
};

#endif /* !PIPE_HPP_ */
