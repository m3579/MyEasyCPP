#ifndef PLAYGROUND_HPP_INCLUDED
#define PLAYGROUND_HPP_INCLUDED

/*
 * playground.hpp
 *
 * /MyEasyCPP/Headers/include/playground.hpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Oct 17, 2015
 *
 *      Purpose:
 *
 *        Usage:
 *
 *        Notes:
 *
 */

access smooth

use fstream

define LIMIT 100

start

    init writer : ofstream ("randInts.txt")

    if not writer.is_open():
        $write("An error occurred while trying to write to the file")

    for i from 1 -> LIMIT:
        writer <-- $rand(1, LIMIT)

    writer.close()

end

#endif // PLAYGROUND_HPP_INCLUDED
