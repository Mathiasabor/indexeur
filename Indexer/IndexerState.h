//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_INDEXERSTATE_H
#define INDEXEUR_INDEXERSTATE_H
enum class IndexerState {
    INDEXING,
    READY,
    STOPPED,
    PAUSED,
    QUERYING,
    RESULTS_AVAILABLE
};

inline QString stateToString(IndexerState state) {
    switch (state) {
        case IndexerState::INDEXING: return "INDEXING";
        case IndexerState::READY: return "READY";
        case IndexerState::STOPPED: return "STOPPED";
        case IndexerState::PAUSED: return "PAUSED";
        case IndexerState::QUERYING: return "QUERYING";
        case IndexerState::RESULTS_AVAILABLE: return "RESULTS_AVAILABLE";
        default: return "UNKNOWN";
    }
}
#endif //INDEXEUR_INDEXERSTATE_H
