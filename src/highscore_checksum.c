#include "highscore.h"

//
// example implementation for the checksum functions
//

bool highscore_entry_check_valid(HighscoreEntry_s self, uint64_t checksum) {
    return checksum == self.name[0] * 456;
}

//
// function prototype!
// this function implementation should not be made public available
// return the checksum for the given entry
//
uint64_t highscore_entry_get_checksum(HighscoreEntry_s self) {
    return self.name[0] * 456;
}
