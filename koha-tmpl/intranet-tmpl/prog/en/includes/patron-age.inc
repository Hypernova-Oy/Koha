[%# The variable patron must be passed, with either a Koha::Patron, or a HASHREF with the 'age' key -%]
[%- USE KohaDates -%]
[%- USE I18N -%]
[%- IF ( patron ) -%]
    [%- IF ( patron.dateofbirth ) -%]
        [%- SET age = (patron.get_age != undef) ? patron.get_age : patron.age -%]
        [%- IF age >= 0 %]
            [%- patron.dateofbirth | $KohaDates -%]
            <span class="age_years">[% I18N.tnx('({age} year)', '({age} years)', age, { age => age }) | html %]</span>
        [%- END -%]
    [%- END -%]
[%- END -%]
