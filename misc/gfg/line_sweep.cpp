typedef complex<int> pnt;   // stores X in real part, Y in imaginary part
 
enum event_type
{
    EVENT_END,       // ordered this way so that events with same x sort this way
    EVENT_VERTICAL,
    EVENT_START
};
 
struct event
{
    event_type type;
    int x;
    int line;        // index into list of lines
 
    event() {}
    event(event_type type, int x, int line) : type(type), x(x), line(line) {}
 
    // sort by X then by type
    bool operator <(const event &b) const
    {
        if (x != b.x) return x < b.x;
        else return type < b.type;
    }
};
 
struct line
{
    int x1, y1, x2, y2;
 
    line() {}
    line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
 
// Returns all intersections between lines. The lines must all be either
// horizontal and vertical, and only horizontal-vertical intersections are
// counted (i.e. not overlaps). Lines are considered to exclude their
// endpoints. Also, each line must have x1 <= x2 and y1 <= y2.
static vector<pnt> hv_intersections(const vector<line> &lines)
{
    int L = lines.size();
    vector<event> events;
    vector<pnt> ans;
 
    // Y coordinates of active lines
    multiset<int> active;
    // Convert lines into events
    for (int i = 0; i < L; i++)
    {
        if (lines[i].y1 != lines[i].y2)
            events.push_back(event(EVENT_VERTICAL, lines[i].x1, i));
        else if (lines[i].x1 != lines[i].x2)
        {
            events.push_back(event(EVENT_START, lines[i].x1, i));
            events.push_back(event(EVENT_END, lines[i].x2, i));
        }
    }
 
    // Sort events by X
    sort(events.begin(), events.end());
 
    // Process events
    for (vector<event>::const_iterator e = events.begin(); e != events.end(); ++e)
    {
        switch (e->type)
        {
        case EVENT_START:
            active.insert(lines[e->line].y1);
            break;
        case EVENT_END:
            active.erase(active.find(lines[e->line].y1));
            break;
        case EVENT_VERTICAL:
            {
                // Iterate over all y values for intersecting horizontal lines
                multiset<int>::const_iterator first, last, i;
                first = active.upper_bound(lines[e->line].y1);
                last = active.lower_bound(lines[e->line].y2);
                for (i = first; i != last; ++i)
                    ans.push_back(pnt(e->x, *i));
            }
            break;
        }
    }
 
    return ans;
}