#include <model/tetromino.hpp>

bool O0[16] =    {0, 0, 0, 0,
                 0, 1, 1, 0,
                 0, 1, 1, 0,
                 0, 0, 0, 0};

bool I0[16] =    {0, 0, 0, 0,
                 1, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0};

bool I1[16] =    {0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 1, 0};

bool S0[16] =     {0, 0, 0, 0,
                 0, 0, 1, 1,
                 0, 1, 1, 0,
                 0, 0, 0, 0};

bool S1[16] =     {0, 0, 1, 0,
                 0, 0, 1, 1,
                 0, 0, 0, 1,
                 0, 0, 0, 0};
bool Z0[16] =    {0, 0, 0, 0,
                 0, 1, 1, 0,
                 0, 0, 1, 1,
                 0, 0, 0, 0};

bool Z1[16] =     {0, 0, 0, 1,
                 0, 0, 1, 1,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

bool L0[16] =     {0, 0, 0, 0,
                 0, 1, 1, 1,
                 0, 1, 0, 0,
                 0, 0, 0, 0};

bool L1[16] =     {0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 1, 1,
                 0, 0, 0, 0};

bool L2[16] =     {0, 0, 0, 1,
                 0, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0};

bool L3[16] =     {0, 1, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

bool J0[16] =     {0, 0, 0, 0,
                 0, 1, 1, 1,
                 0, 0, 0, 1,
                 0, 0, 0, 0};

bool J1[16] =     {0, 0, 1, 1,
                 0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

bool J2[16] =     {0, 1, 0, 0,
                 0, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0};

bool J3[16] =     {0, 0, 1, 0,
                 0, 0, 1, 0,
                 0, 1, 1, 0,
                 0, 0, 0, 0};

bool T0[16] =     {0, 0, 0, 0,
                 0, 1, 1, 1,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

bool T1[16] =     {0, 0, 1, 0,
                 0, 0, 1, 1,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

bool T2[16] =     {0, 0, 1, 0,
                 0, 1, 1, 1,
                 0, 0, 0, 0,
                 0, 0, 0, 0};

bool T3[16] =     {0, 0, 1, 0,
                 0, 1, 1, 0,
                 0, 0, 1, 0,
                 0, 0, 0, 0};

Tetromino::Tetromino(char type, int orient, 
                        int col, int row)
    : m_type(type), m_orient(orient), m_col(col), m_row(row) 
{ 
    m_pDesc = GetDesc(type, orient);
}

bool const* Tetromino::GetDesc() const {
    return m_pDesc;
}

char Tetromino::GetType() const {
    return m_type;
}

int Tetromino::GetOrient() const {
    return m_orient;
}

int Tetromino::GetX() const {
    return m_col;
}

int Tetromino::GetY() const {
    return m_row;
}

void Tetromino::SetX(int x) {
    m_col = x;
}

void Tetromino::SetY(int y) {
    m_row = y;
}

void Tetromino::ShiftRight() {
    ++m_col;
}

void Tetromino::ShiftLeft() {
    --m_col;
}

void Tetromino::ShiftDown() {
    ++m_row;
}

void Tetromino::ShiftUp() {
    --m_row;
}

void Tetromino::SetOrient(int orient) {
    m_orient = orient;
    m_pDesc = GetDesc(m_type, m_orient); 
}

void Tetromino::RotateLeft() {
    if (m_type == 'O') {
        // Do nothing!
    }
     else if (m_type == 'I' || m_type == 'S' || m_type == 'Z') {
        m_orient = (m_orient+1)%2;
    }
    else if (m_type == 'L' || m_type == 'J' || m_type == 'T') {
        m_orient = (m_orient+1)%4;
    }
    m_pDesc = GetDesc(m_type, m_orient);
}

void Tetromino::RotateRight() {
    if (m_type == 'O') {
        // Do nothing!
    }
     else if (m_type == 'I' || m_type == 'S' || m_type == 'Z') {
        m_orient = (m_orient+1)%2;
    }
    else if (m_type == 'L' || m_type == 'J' || m_type == 'T') {
        m_orient = (m_orient-1+4)%4;
    }
    m_pDesc = GetDesc(m_type, m_orient);
}

bool Tetromino::operator== (Tetromino const& o) const {
    return (m_type == o.m_type &&
            m_orient == o.m_orient &&
            m_row == o.m_row &&
            m_col == o.m_col);
}

bool Tetromino::operator!= (Tetromino const& o) const {
    return !(*this == o);
}

bool const* Tetromino::GetDesc(char type, int orient) const {
    bool const* desc = NULL;
    if (type == 'O') {
        desc = &(O0[0]);
    }
    else if (type == 'I') {
        if (orient == 0)
            desc = &(I0[0]);
        else if (orient == 1)
            desc = &(I1[0]);
    }
    else if (type == 'S') {
        if (orient == 0)
            desc = &(S0[0]);
        else if (orient == 1)
            desc = &(S1[0]);
    }
    else if (type == 'Z') {
        if (orient == 0)
            desc = &(Z0[0]);
        else if (orient == 1)
            desc = &(Z1[0]);
    }
    else if (type == 'L') {
        if (orient == 0)
            desc = &(L0[0]);
        else if (orient == 1)
            desc = &(L1[0]);
        else if (orient == 2)
            desc = &(L2[0]);
        else if (orient == 3)
            desc = &(L3[0]);
    }
    else if (type == 'J') {
        if (orient == 0)
            desc = &(J0[0]);
        else if (orient == 1)
            desc = &(J1[0]);
        else if (orient == 2)
            desc = &(J2[0]);
        else if (orient == 3)
            desc = &(J3[0]);
    }
    else if (type == 'T') {
        if (orient == 0)
            desc = &(T0[0]);
        else if (orient == 1)
            desc = &(T1[0]);
        else if (orient == 2)
            desc = &(T2[0]);
        else if (orient == 3)
            desc = &(T3[0]);
    }
    return desc;
}

std::ostream& operator<< (std::ostream& out, Tetromino const& t) {
    out << "(" << t.GetX() << ", " << t.GetY() << ")" << std::endl;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            bool set = t.m_pDesc[j*4+i];
            out << set;
        }
        out << std::endl;
    }
    return out;
}

