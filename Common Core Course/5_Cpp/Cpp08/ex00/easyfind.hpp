#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

template <typename container>
typename container::iterator easyfind(container& cont, int n)
{
        typename container::iterator i = find(cont.begin(), cont.end(), n);
        if (i != cont.end())
                return (i);
        throw std::logic_error("no occurrence found");
}

#endif