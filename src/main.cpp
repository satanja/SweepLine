#include <iostream>
#include <queue>
#include <set>

struct Segment
{
    float begin;
    float end;
    void print()
    {
        std::cout << begin << " " << end;
    }
};

struct EndPoint
{
    float x;
    bool isBegin;
    Segment * s;
    bool operator<(const EndPoint &b) const
    {
        if (x == b.x)
        {
            return isBegin; // end of segments are always first
        }
        else
        {
            return x > b.x; // sort in increasing order
        }
    }
};

void read(std::priority_queue<EndPoint>& queue, std::vector<Segment>& segs)
{
    int n;
    std::cin >> n;
    segs.resize(n);

    for (int i = 0; i < n; i++)
    {   
        float b, e;
        std::cin >> b >> e;

        segs[i].begin = b;
        segs[i].end = e;
        
        EndPoint p = {b, true, &segs[i]};
        EndPoint q = {e, false, &segs[i]};
        queue.emplace(p);
        queue.emplace(q);
    }
}

int main()
{
    std::priority_queue<EndPoint> queue;
    std::vector<Segment> segs;
    std::set<Segment*> status;

    read(queue, segs);

    while (!queue.empty())
    {
        EndPoint p = queue.top();
        queue.pop();
        if (p.isBegin)
        {   
            for (Segment * s : status)
            {
                // cleanup
                std::cout << "Intersection: ";
                s->print();
                std::cout << " with ";
                p.s->print();
                std::cout << "\n";
            }
            status.insert(p.s);
        }
        else
        {   
            status.erase(p.s);
        }
    }
    return 0;
}