/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:11:08 by pshamkha          #+#    #+#             */
/*   Updated: 2025/02/15 15:11:16 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
#define CAT_H_

#include "Brain.h"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    void makeSound() const;
    Brain* getBrain() const;
private:
    Brain *mBrain;
};

#endif //CAT_H_
