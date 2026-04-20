# Control.Serialization.Api

`PiSubmarine.Control.Serialization.Api` defines the transport-agnostic
contracts for converting operator control commands to and from bytes.

## Responsibility

This module owns:

- `Control::ISerializer`
- `Control::IDeserializer`
- serialization-specific error codes

It does not own:

- any concrete payload format
- any network transport
- control command production or consumption

## Design

The serializer and deserializer operate on
`PiSubmarine::Control::Api::Input::OperatorCommand`, so transport modules can
stay agnostic about the concrete encoding while operator-side and drone-side
code reuse the same control model.
