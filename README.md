# bicron
Bicron determines the desired state of given keys based on a predefined configuration in relation to the current time. While it was originally intended to calculate the state of io's, I strive to give it a broader spectrum of usage.

The project is still in its early stages and even if the readme file seems complete, it does reflect the desired destination more than the current state.

## What it does
When the application is started, a configuration file is read which will be parsed from top to bottom. Each entry might contain date and time information (in full or partial), which gets compared to the current date and time. When the given date and time information is smaller than the current one, the specified state will be assigned to the specified key of that entry.

After processing all entries, a list of all known keys and their last assigned state is printed.

## Features
- [ ] Applying rules loaded from configuration file based on local time
- [ ] Passing manual date and time for configuration test purposes
- [ ] Specifying the output format via configuration
- [ ] Handling of time zones


## Getting Started

### Prerequisites
This list is currently empty.

### Compilation
```
mkdir build
cmake ..
make
```

### Installation
There is currently no installation procedure planned. The application might be started from anywhere, as long as the configuration file is passed via command line argument.

## Configuration
A typical configuration file might look like this, while the explanation can be found underneath.

```
{
  "cron": [
    {"key": "0", "state": "off"},
    {"key": "1", "state": "off"},

    {"hour": 8, "key": "0", "state": "on"},
    {"hour": 20, "key": "0", "state": "off"},
    {"month": 5, "key": "1", "state": "on" },
    {"month": 9, "key": "1", "state": "off"}
  ]
}
```

The `cron` section contains a list of all rules to be applied to the specified keys. When no date and time information is given, the rule is always true and the given state assigned to the specified key. This is shown with the first two entries, which can be used to set initial or default values. Be aware that such a rule would overule any previous state assigned to that key.

When date and/or time information is given, the data is compared via *less or equal* with the current date and/or time information as shown with the last 4 rules. Rule number 3 would apply every day for the hours 8, 9 till 24 and therefore set the key with id `0` to `on`, wile rule number 4 would overrule rule number 3 every day for the hours 20 till 24.

Following states can be assumed at following time points:
- **2017-03-01 06:22**: 0: off; 1: off;
- **2017-05-21 14:58**: 0: on; 1: on;
- **2017-12-24 22:00**: 0: off; 1: off;

## Output
For now the output can be expected to look like `<key>:<value>` while each entry is printed at a separate line. The order of keys is not garanteed.

Example:
```
0:on
1:off
```

## Built With

- [Catch](https://github.com/philsquared/Catch) - Test framework
- [Json](https://github.com/nlohmann/json) - Parsing configuration files

## License
This project is licensed under the MIT License - see the LICENSE.md file for details
